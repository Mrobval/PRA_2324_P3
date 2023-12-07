#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"

#include "../../pract1/PRA_2324_P1/ListLinked.h"

template <typename V>
class HashTable: public Dict<V> {
	private:
		int n;
		int max;
		ListLinked<TableEntry<V>>*table;
		int h(std::string key){
			int sum = 0;
			for (size_t i=0; i<key.length(); i++) {
				sum += static_cast<int>(key.at(i));  // Suma los valores ASCII numéricos de los caracteres
			}
			return sum % max;  // Devuelve el resto de la división entre la suma y el tamaño de la tabla
    		};
	public:
		HashTable(int size){
			table = new ListLinked<TableEntry<V>>[size];
			int n = 0;
			int max = size;
		};
		~HashTable(){
			delete[] table;
		};
		int capacity(){
			return max;
		};
		friend std::ostream&operator>>(std::ostream &out, const HashTable<V> &th){
			out << th.key << th.value;
			return out;
		};
		V operator[](std::string key){
			for (int i=0; i < capacity(); i++){
				if (ListLinked<TableEntry<V>>::search(table[i], key) != nullptr){
					return ListLinked<TableEntry<V>>::search(table[i], key)->value;
				}else{
					throw std::runtime_error("No existe la clave");
				}
			}
		};
		void insert(std::string key, V value) override{
			int index = h(key);
			for (int i=0; i < capacity(); i++){
				if(ListLinked<TableEntry<V>>::search(table[i], key) != nullptr){
					throw std::runtime_error("Ya exite la clave");
				}
				else{
					ListLinked<TableEntry<V>>::insert(table[i], key);
					n++;	
				}
			}
		};
		V search(std::string key) override{
			int index = h(key);
			for (int i=0; i<capacity(); i++){
				if (ListLinked<TableEntry<V>>::search(table[i], key)){
					return ListLinked<TableEntry<V>>::search(table[i], key)->value;
				}
			}
			throw std::runtime_error("La clave no se encuentra");
		};
		V remove(std::string key) override{
			int index = h(key);
			for (int i=0; i < capacity(); i++){
				if (ListLinked<TableEntry<V>>::search(table[i], key) != nullptr){
					ListLinked<TableEntry<V>>::remove(table[i]);
				}
				n--;
			}
			throw std::runtime_error("No existe esa clave");
		};
		int entries() override{
			return n;
		};
};
#endif

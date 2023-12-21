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
			//table = new ListLinked<TableEntry<V>>[size];
			for (int i=0; i < size; i++){
				table[i] = ListLinked<TableEntry<V>>();
			}
			n = 0;
			max = size;
		};
		~HashTable(){
			delete[] table;
		};
		int capacity() const{
			return max;
		};
		friend std::ostream&operator<<(std::ostream &out, const HashTable<V> &th){
			out << th; //Sólo hace la primera cubeta?? Hay que hacer un bucle para recoger toda la tabla??
			return out;
		};
		V operator[](std::string key){
			if(!search(key)){
				throw std::runtime_error("La clave no se encuentra");
			}
			std::ostream&operator<<(std::ostream &out, const TableEntry<V> &key);
		};
		void insert(std::string key, V value) override{
			int index = h(key);
			if (search(key)){
				throw std::runtime_error("La clave ya existe");
			}
			table(index).prepend(key);
		};
		V search(std::string key) override{
			int index = h(key);
			int position = table(index).search(key);
			if (position){
				char elemento = table(index).get(position);
				if (elemento){
					std::ostream& operator<<(std::ostream &out, const TableEntry<V> &elemento);
				}
				
			}
			throw std::runtime_error("La clave no se encuentra");
		};
		V remove(std::string key) override{
			int index = h(key);
			if (!search(key)){
				throw std::runtime_error("No se ha encontrado la calve que buscas");
			}
			int position = table(index).search(key);
			table(index).remove(position);
		};
		int entries() const{
			return n;
		};
};
#endif

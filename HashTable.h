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
			/*for (int i=0; i < size; i++){
				table[i] = new ListLinked<TableEntry<V>>();
			}*/
			n = 0;
			max = size;
		};
		~HashTable(){
			delete[] table;
		};
		int capacity() const{
			if (table == nullptr){
				return 0;
			}
			return max;
		};
		friend std::ostream&operator<<(std::ostream &out, const HashTable<V> &th){
			for (int i=0; i<th.max; i++){
				out<< "Cubeta "<< i<< ": "<< std::endl;
				out<< th.table[i]<< std::endl;
			}
			return out;
		};
		V operator[](std::string key){
			int index = h(key);
			int position = table[index].search(key);
			if(position){			
				//std::ostream&operator<<(std::ostream &out, const TableEntry<V> &key);
				return table[index].get(position).value;
			}else{
				throw std::runtime_error("La clave no se encuentra");
			}
		};
		void insert(std::string key, V value) override{
			int index = h(key);
			int position = table[index].search(key);
			if (position == -1){
				table[index].prepend(TableEntry<V>(key, value));
				n++;
			}else{
				throw std::runtime_error("La clave ya existe");
			}
		};
		V search(std::string key) override{
			int index = h(key);
			int position = table[index].search(key);		
			//std::cout<< "La posicion es: "<< position<< std::endl;
			if (position > -1){
				return table[index].get(position).value;
				//std::ostream& operator<<(std::ostream &out, const TableEntry<V> &elem);
				
			}else{
				throw std::runtime_error("La clave no se encuentra");
			}
		};
		V remove(std::string key) override{
			int index = h(key);
			int position = table[index].search(key);
			//std::cout<< "La posicion es: "<< position<< std::endl;
			if (position > -1){
				return table[index].remove(position).value;
				n--;
			}else{
				throw std::runtime_error("No se ha encontrado la calve que buscas");
			}
		};
		int entries() const override{
			return n;
		};
};
#endif

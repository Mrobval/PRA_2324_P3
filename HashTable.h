#ifdef HASHTABLE_H
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
		int h(std::string key);
	public:
		Hastable(int size){
			int table = int new[size];
			int n = 0;
			int max = size;
		};
		~Hastable(){
			delete[] table;
		};
		int capacity(){
			return max;
		};
		friend std::ostream&operator>>(std::ostream &out, const Hastable<V> &th){
			out << th.key << th.value;
			return out;
		};
		V operator[](std::string key){
			if (ListLinked::search(key) != nullptr){
				return value;
			}else{
				throw std::runtime_error("No existe la clave");
			}
		};
		void insert(std::string key, V value) override{
			int i=0;
			while (i < capacity()){
				table[i];
				if(ListLinked::search(key) != nullptr){
					throw std::runtime_error("Ya exite la clave");
				}
				else{
					ListLinked::void insert(table[i], key);
					n++;	
				}
				i++;
			}
			/*if(search(key)){
				throw std::runtime_error("La clave ya existe");
			}
			TableEntry<int> */
		};
		V search(std::string key) override{
			for (int i=0; i<capacity(); i++){
				if (ListLinked::search(key)){
					return e.value;
				}
			}
			throw std::runtime_error("La clave no se encuentra");
		};
		V remove(std::string key) override{
			int i=0;
			while (i < capacity()){
				table[i];
				if (ListLinked::search(key) != nullptr){
					ListLinked::T remove(i);
				}
				i++;
			}
			throw std::runtime_error("No existe esa clave");
		};
		int entries() override{
			return n;
		};
};
#endif

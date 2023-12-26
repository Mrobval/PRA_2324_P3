#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <iostream>
#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"

template <typename V>
class BSTreeDict: public Dict<V> {

    private:
        // Implementación métodos privados
	BSTree<TableEntry<V>>* tree;

    public:
        // Implementación métodos públicos
        BSTreeDict(){
		tree = new BSTree<TableEntry<V>>;
	};
	~BSTreeDict(){
		delete tree;
	};
	friend std::ostream&operator<<(std::ostream& out, const BSTreeDict<V> &bs){
		out << bs.tree;
		return out;
	};
	V operator[](std::string key){
		return search(key);
	};
	void insert(std::string key, V value) override{
		TableEntry<V> resultado = tree->search(TableEntry<V>(key, V()));
		if (resultado == TableEntry<V>()){
			return tree->insert(TableEntry<V>(key, value));
		}else{
			throw std::runtime_error("La clave ya existe");
		}
	};
	V search(std::string key) override{
		//if (tree->search(TableEntry<V>(key,V()))){
		try{
			Dict.search(key);
			return tree->search(TableEntry<V>(key, V())).value;
			//return tree->search(TableEntry<V>(key, V())).value;
		}
		catch (std::runtime_error &e){
			std::cout<< e.what()<< std::endl;
		/*else{
			throw std::runtime_error("No se encuentra la clave"); */
		}
	};
	V remove(std::string key) override{
		try{
			Dict.search(key);
			return tree->search(TableEntry<V>(key, V())).value;
			tree->remove(TableEntry<V>(key, V()));
		}
		catch (std::runtime_error &e){
			std::cout<< e.what()<< std::endl;
		}
	};
	int entries() const override{
		return tree->size();
	};
};

#endif

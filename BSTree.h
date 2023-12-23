#ifndef BSTREE_H
#define BSTREE_H

#include <ostream>
#include <stdexcept>
#include "BSNode.h"

template <typename T> 
class BSTree {
    private:
        //miembros privados
	int nelem;
	BSNode<T>* root;
	BSNode<T>* search(BSNode<T>* n, T e) const{
		if (n == nullptr){
			throw std::runtime_error("No se ha encontrado el nodo deseado");
		}
		else if (n->elem < e){
			return search(n->right, e);
		}
		else if (n->elem > e){
			return search(n->left, e);
		}
		else{
			return n;
		}
	};
	BSNode<T>* insert(BSNode<T>* n, T e){
		if (n == nullptr){
			new BSNode<T>*;
		}
		else if (n->elem == e){
			throw std::runtime_error("Ya existe ese elemento en el ABB");
		}
		else if (n->elem < e){
			n->right = insert(n->right, e);
		}
		else{
			n->left = insert(n->left, e);
		}
		return n;
	};
	void print_inorder(std::ostream& out, BSNode<T> n) const{
		if (n == nullptr){
			throw std::runtime_error("No hay elementos");
		}
		else if (n.left != nullptr){
			print_inorder(out, n->left);
		}
		print_inorder(out, n);
		if (n.right != nullptr){
			print_inorder(out, n->right);
		}
	};
	BSNode<T>* remove(BSNode<T>* n, T e){
		if (n == nullptr){
			throw std::runtime_error("No se encuentra el elemento");
		} 
		else if (n->elem < e){
			n->right = remove(n->right, e);
		}
		else if (n->elem > e){
			n->left = remove(n->left, e);
		}
		else{
			if (n->left != nullptr && n->right != nullptr){
				n->elem = max(n->left);
				n->left = remove_max(n->left);
			}
			else{
				n = (n->left != nullptr)?n->left: n->right;
			}
		}
		return n;
	};
	T max(BSNode<T>* n) const{
		if (n == nullptr){
			throw std::runtime_error("No hay elementos mayores al root del (sub-)arbol");
		}
		else if (n->right != nullptr){
			return max(n->right);
		}
		else{
			return n->elem;
		}
	};
	BSNode<T>* remove_max(BSNode<T>* n){
		if (n->right == nullptr){
			return n->left;
		}
		else{
			n->right = remove_max(n->right);
			return n;
		}
	};
	void delete_cascade(BSNode<T>* n){
		if (n == nullptr){
			throw std::runtime_error("El arbol ya está vacío");
		}
		else if (n->left != nullptr){
			delete_cascade(n->left);
		}
		else if (n->right != nullptr){
			delete_cascade(n->right);
		}
		delete [] n;
	};
    public:
        // miembros públicos
	BSTree(){
		root = nullptr;
	};
	int size() const{
		return nelem;
	};
	T search(T e) const{
		search(root, e);
	};
	T operator[](T e)const{
		search(e);
	};
	void insert (T e){
		root = insert(root, e);
	};
	friend std::ostream&operator<<(std::ostream &out, const BSTree<T> &bst){
		bst.print_inorder(out, bst.nelem);
		return out;
	};
	void remove (T e){
		root = remove(root, e);
	};
	~BSTree(){
		delete_cascade(root);
	};
};

#endif

#ifndef bintree_11_h
#define bintree_11_h

#include "bintree_eda.h"
#include <vector>
#include <algorithm>
#include <iostream>

template<class T>

class bintree_11 : public bintree<T> {

	using Link = typename bintree<T>::Link;

public:
	// árbol vacío
	bintree_11() : bintree<T>(){}

	// árbol con dos hijos
	bintree_11(bintree_11<T> const& l, T const& e, bintree_11<T> const& r) :
		bintree<T>(l, e, r) {}

	int numNodos() {
		return numNodos(this->raiz);
	}

	int numHojas() {
		return numHojas(this->raiz);
	}

	int altura() {
		return altura(this->raiz);
	}

	std::vector<T> frontera() {
		return frontera(this->raiz);
	}

	T getMin() {
		return getMin(this->raiz);
	}

private:
	int numNodos(Link raiz) {
		if (raiz == nullptr) return 0;
		else if (raiz->left == nullptr && raiz->right == nullptr) return 1;
		else {
		return 1 + numNodos(raiz->left) + numNodos(raiz->right);
		}
	}

	int numHojas(Link raiz) {
		if (raiz == nullptr) return 0;
		else if (raiz->right == nullptr && raiz->left == nullptr) return 1;
		else {
			int hojasIzq = 0, hojasDer = 0;
			if (raiz->right != nullptr) hojasDer = numHojas(raiz->right);
			if (raiz->left != nullptr) hojasIzq = numHojas(raiz->left);
			return hojasIzq + hojasDer;
		}
	}

	int altura(Link raiz) {
		if (raiz == nullptr) return 0;
		else if (raiz->left == nullptr && raiz->right == nullptr) return 1;
		else return 1 + std::max(altura(raiz->left), altura(raiz->right));
	}

	std::vector<T> frontera(Link raiz) {
		if (raiz == nullptr) return {};
		else if (raiz->left == nullptr && raiz->right == nullptr) return { raiz->elem };
		else {
			std::vector<T> izq = {}, der = {};
			if (raiz->left != nullptr) izq = frontera(raiz->left);
			if (raiz->right != nullptr) der = frontera(raiz->right);
			for (T e : der) izq.push_back(e);
			return izq;
		}
	} 

	T getMin(Link raiz) {
		if (raiz != nullptr) {
			if (raiz->left == nullptr && raiz->right == nullptr) return raiz->elem;
			else {
				T izq = raiz->elem, der = raiz->elem;
				if (raiz->left != nullptr) izq = getMin(raiz->left);
				if (raiz->right != nullptr) der = getMin(raiz->right);
				return std::min(izq, std::min(der, raiz->elem));
			}
		}
	}
};

// lee un árbol binario de la entrada estándar
template <typename T>
inline bintree_11<T> leerArbolExt(T vacio) {
	T raiz;
	std::cin >> raiz;
	if (raiz == vacio) { // es un árbol vacío
		return {};
	}
	else { // leer recursivamente los hijos
		auto iz = leerArbolExt(vacio);
		auto dr = leerArbolExt(vacio);
		return { iz, raiz, dr };
	}
}

#endif
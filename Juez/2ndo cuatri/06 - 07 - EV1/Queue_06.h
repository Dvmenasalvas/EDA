#include <iostream><
#include "queue_eda.h"

template <class T>

class queue_06 : public queue<T> {

	using Nodo = typename queue<T>::Nodo; // para poder usar Nodo aquí

public:

	void invierteSeg(int P, int L) {
		Nodo * preInicio = nullptr;
		Nodo * inicio = this->prim;
		for (int i = 1; i < P; i++) {
			preInicio = inicio;
			inicio = inicio->sig;
		}

		Nodo * anterior = preInicio;
		Nodo * actual = inicio;
		Nodo * siguiente = inicio->sig;

		for (int i = 1; i < L; i
			++) {
			anterior = actual;
			actual = siguiente;
			siguiente = siguiente->sig;
			actual->sig = anterior;
		}

		if (preInicio == nullptr) this->prim = actual;
		else preInicio->sig = actual;

		if (siguiente == nullptr) {
			this->ult = inicio;
			inicio->sig = nullptr;
		} else inicio->sig = siguiente;
	}

	void print(std::ostream & o = std::cout) const {
		if (this->nelems > 0) {
			Nodo * p = this->prim;
			o << p->elem << " ";
			for (int i = 1; i < this->nelems; i++) {
				p = p->sig;
				o << p->elem << " ";
			}
		}
		o << '\n';
	}



	// Duplicar los nodos de una lista enlazada simple

	void duplica() {
		if (this->nelems > 0) {
			Nodo * actual = this->prim;
			int vueltas = this->nelems;
			actual->sig = new Nodo(actual->elem, actual->sig);
			this->nelems++;
			for (int i = 1; i < vueltas; i++) {
				actual = (actual->sig)->sig;
				actual->sig = new Nodo(actual->elem, actual->sig);
				this->nelems++;
			}
		}
	}

	void invierte() {
		if (this->nelems > 1) {
			Nodo * anterior = this->prim;
			Nodo * actual = anterior->sig;
			Nodo * siguiente = nullptr;
			if (this->nelems > 2) {
				siguiente = actual->sig;
			}
			this->ult = anterior;
			anterior->sig = nullptr;
			actual->sig = anterior;
			for (int i = 1; i < this->nelems - 1; i++) {
				anterior = actual;
				actual = siguiente;
				siguiente = siguiente->sig;
				actual->sig = anterior;
			}
			this->prim = actual;
		} 
	}

	void borraPares() {
		if (this->nelems > 1) {
			int elementos = this->nelems;
			Nodo * anterior = this->prim;
			Nodo * borrado = anterior->sig;
				for (int i = 1; i < elementos; i = i + 2) {
					anterior->sig = borrado->sig;
					delete borrado;
					anterior = anterior->sig;
					if (i < elementos - 1) {
						borrado = anterior->sig;
					}
					this->nelems--;
				}
		}
	}

	void eliminaCreciente() {
		if (this->nelems > 1) {
			int elementos = this->nelems;
			Nodo* anterior = this->prim;
			Nodo* actual = anterior->sig;
			for (int i = 1; i < elementos; i++) {
				if (actual->elem < anterior->elem) {
					anterior->sig = actual->sig;
					delete actual;
					actual = anterior->sig;
					this->nelems--;
				} else {
					anterior = anterior->sig;
					actual = actual->sig;
				}
			}
		}
	}

};
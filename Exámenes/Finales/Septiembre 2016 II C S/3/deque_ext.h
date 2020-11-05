#include "deque_eda.h"

template<class T>
class deque_ext : public deque<T> {
	
	using Nodo = typename deque<T>::Nodo;

public:
	void splice(deque_ext<T> & l, T const& v1, T const& v2, T const& v3) {
		//Buscamos v1
		auto w1 = this->fantasma;
		buscar(*this, v1, w1);

		auto w2 = l.fantasma;
		if (w1 != this->fantasma) {
			buscar(l, v2, w2);
		}
		auto w3 = w2;
		int elems;
		if (w2 != l.fantasma) {
			elems = buscar(l, v3, w3);
		}
		if (w3 != l.fantasma) {
			//Borramos de l
			enlazar(w2->ant, w3->sig);
			//Añadimos a this
			enlazar(w3, w1->sig);
			enlazar(w1, w2);

			//Ajustamos elementos
			l.nelems -= elems;
			this->nelems += elems;
		}
	}

	void print() const {
		auto act = this->fantasma->sig;
		while (act != this->fantasma) {
			cout << act->elem << " ";
			act = act->sig;
		}
		cout << '\n';
	}
protected:
	void enlazar(Nodo* & a, Nodo* & b) {
		a->sig = b;
		b->ant = a;
	}
	int buscar(deque_ext<T> const&l, T const& e, Nodo* & p) {
		p = p->sig;
		int res = 2;
		while (p != l.fantasma && p->elem != e) {
			p = p->sig;
			res++;
		}
		return res;
	}
};
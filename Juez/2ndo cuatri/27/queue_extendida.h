#include "queue_eda.h"

template<class T>
class queue_ext : public queue<T> {

	using Nodo = typename queue<T>::Nodo;

public:
	void insertar(queue<T> q, int p) {
		if (q.size() > 0) {
			Nodo * despues;
			//Juntamos la parte de la izquierda y guardamos el nodo de despues
			if (p == 0) {
				despues = this->prim;
				this->prim = q.prim;
			}
			else {
				auto act = this->prim;
				//Avanzamos hasta el nodo anterior al nuevo segmento
				for (int i = 0; i < p - 1; i++)
					act = act->sig;
				despues = act->sig;
				act->sig = q.prim;
			}

			//Juntamos la parte de la derecha
			if (despues == nullptr) {
				q.ult->sig = nullptr;
				this->ult = q.ult;
			}
			else 
				q.ult->sig = despues;
		}
	}

	void print() {
		auto act = this->prim;
		while (act != nullptr) {
			cout << act->elem << " ";
			act = act->sig;
		}
	}
};
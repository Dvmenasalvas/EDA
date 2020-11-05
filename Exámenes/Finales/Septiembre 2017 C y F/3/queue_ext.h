#include "Header.h"



template <class T>
class queue_ext : public queue<T> {

	using Nodo = typename queue<T>::Nodo;

public:
	void cuela(const T & a, const T & b) {
		//Buscamos a
		auto A = this->prim;
		while (A != nullptr && A->elem != a)
			A = A->sig;
		//Buscamos b
		if (A != nullptr) {
			auto B = A->sig;
			auto antB = A;
			while (B != nullptr && B->elem != b) {
				B = B->sig;
				antB = antB->sig;
			}
			//Tenemos B y A y no estan seguidos
			if (B != nullptr && antB != A) {
				//Enlazamos la parte de b
				antB->sig = B->sig;
				if (antB->sig == nullptr)
					this->ult = antB;
				//Enlazamos la parte de A
				B->sig = A->sig;
				A->sig = B;
			}
		}
	}

	void print() {
		auto act = this->prim;
		while (act != nullptr) {
			cout << act->elem << " ";
			act = act->sig;
		}
		cout << '\n';
	}
}; 

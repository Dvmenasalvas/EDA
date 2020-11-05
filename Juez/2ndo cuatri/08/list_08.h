#include "list_eda.h"

template<class T>

class list_08 : public list<T> {

public:
	template <class Predicate>
	void remove_if(Predicate pred) {
		auto anterior = this->fantasma;
		auto actual = anterior->sig;
		while (actual != this->fantasma) {
			if (pred(actual->elem)) {
				actual = actual->sig;
				delete anterior->sig;
				anterior->sig = actual;
				actual->ant = anterior;
				this->nelems--;
			} else {
				anterior = anterior->sig;
				actual = actual->sig;
			}
		}
	}
};

template<class T>
inline std::ostream & operator << (std::ostream & o, list<T> lista) {
	for (T obj : lista) {
		o << obj << '\n';
	}
	return o;
}
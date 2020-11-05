//
//  conjunto.h
//

#ifndef conjunto_h
#define conjunto_h

#include <cstddef>    // size_t
#include <stdexcept>  // std::domain_error
#include <utility>    // std::move
#include <iostream>
#include <fstream>

template <class T>
class set {
public:
	set(size_t tam = TAM_INICIAL); // constructor
	set(set<T> const& other); // constructor por copia
	set<T> & operator=(set<T> const& other); // operador de asignación
	~set(); // destructor
	void insert(T e);
	void insertK(T e);
	void insertFull(T e);
	bool contains(T e) const;
	void erase(T e);
	bool empty() const;
	size_t size() const;
	T menor() const;
	bool full() const;
	void quitarMenor();
	void write(std::ostream & out) const ;
private:
	const static size_t TAM_INICIAL = 8;
	size_t contador;
	size_t capacidad;
	T * datos;
	void amplia();
	void libera();
	void copia(set<T> const& other);
	int busquedaBinAux(T buscado, int ini, int fin) const;
	int busquedaBin(T buscado) const;
};

template <class T>
set<T>::set(size_t tam) : contador(0), capacidad(tam), datos(new T[capacidad]) {}

template <class T>
set<T>::~set() {
	libera();
}

template <class T>
void set<T>::libera() {
	delete[] datos;
}

/** Constructor por copia */
template <class T>
set<T>::set(set<T> const& other) {
	copia(other);
}

/** Operador de asignación */
template <class T>
set<T> & set<T>::operator=(set<T> const& other) {
	if (this != &other) {
		libera();
		copia(other);
	}
	return *this;
}

template <class T>
void set<T>::copia(set<T> const& other) {
	capacidad = other.capacidad;
	contador = other.contador;
	datos = new T[capacidad];
	for (size_t i = 0; i < contador; ++i)
		datos[i] = other.datos[i];
}

template<class T>
inline int set<T>::busquedaBinAux(T buscado, int ini, int fin) const
{
	if (ini == fin) return ini;
	else if (ini == fin - 1) {
		if (buscado < datos[ini]) return ini;
		else return ini + 1;
	}
	int mitad = ini + (fin - ini) / 2;
	if (buscado < datos[mitad]) return busquedaBinAux(buscado, ini, mitad);
	else return busquedaBinAux(buscado, mitad, fin);
}
template <class T>
int set<T>::busquedaBin(T buscado) const {
	return busquedaBinAux(buscado, 0, contador);
}



template <class T>
void set<T>::insert(T e) {
	if (!contains(e)) {
		if (contador == capacidad)
			amplia();
		int pos = busquedaBin(e);
		for (int i = contador; i > pos; i--) 
			datos[i] = datos[i - 1];
		datos[pos] = e;
		++contador;
	}
}

template <class T>
void set<T>::insertFull(T e) {
	if (!contains(e)) {
		int pos = busquedaBin(e);
		if (pos != 0) {
			pos--;
			for (int i = 0; i < pos; i++)
				datos[i] = datos[i + 1];
			datos[pos] = e;
		}
	}
}

template<class T>
void set<T>::insertK(T e)
{
	if (!full()) insert(e);
	else insertFull(e);
}

template <class T>
bool set<T>::contains(T e) const {
	size_t i = 0;
	while (i < contador && datos[i] != e)
		++i;
	return i < contador;
}

template <class T>
void set<T>::amplia() {
	T * nuevos = new T[2 * capacidad];
	for (size_t i = 0; i < capacidad; ++i)
		nuevos[i] = std::move(datos[i]);
	delete[] datos;
	datos = nuevos;
	capacidad *= 2;
}

template <class T>
void set<T>::erase(T e) {
	size_t i = 0;
	while (i < contador && datos[i] != e)
		++i;
	if (i < contador) {
		datos[i] = datos[contador - 1];
		--contador;
	}
	else
		throw std::domain_error("El elemento no esta");
}


template <class T>
bool set<T>::empty() const {
	return contador == 0;
}

template <class T>
size_t set<T>::size() const {
	return contador;
}

template<class T>
T set<T>::menor() const
{
	return datos[0];
}

template<class T>
inline bool set<T>::full() const
{
	return contador == capacidad;
}

template<class T>
void set<T>::quitarMenor()
{
	for (int i = 0; i < contador - 1; i++)
		datos[i] = datos[i + 1];
	contador--;
}

template<class T>
void set<T>::write(std::ostream & out) const
{
	for (int i = 0; i < contador; i++)
		out << datos[i] << " ";
	out << '\n';

}

template<class T>
inline std::ostream & operator<<(std::ostream & out, set<T> const &s){
	s.write(out);
	return out;
}

#endif // conjunto_h
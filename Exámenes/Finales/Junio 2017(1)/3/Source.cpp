// Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include "bintree_eda.h"
using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

int singular(bintree<int> const& a, int ancestros, int & descendientes) {
	if (a.left().empty() && a.right().empty()) {
		descendientes = a.root();
		return 0 == ancestros;
	}
	int singIzq = 0, descIzq = 0;
	if (!a.left().empty()) 
		singIzq = singular(a.left(), ancestros + a.root(), descIzq);
	
	int singDer = 0, descDer = 0;
	if (!a.right().empty())
		singDer = singular(a.right(), ancestros + a.root(), descDer);

	descendientes = a.root() + descIzq + descDer;
	return singIzq + singDer + (ancestros == (descIzq + descDer));
}

int singular(bintree<int> const& a) {
	int descendientes = 0;
	return a.empty() ?  0 : singular(a, 0, descendientes);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	auto a = leerArbol(-1);

	if (!cin)
		return false;

	cout << singular(a) << '\n';
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
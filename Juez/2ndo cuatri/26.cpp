// Grupo XYZ, Fulano y Mengano
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <string>
#include <algorithm>
#include "bintree_eda.h"

using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

//O(N) lineal en el numero de nodos del arbol
int mejorCamino(bintree<int> bt, int & dragones) {	
	if (bt.empty()) {
		dragones = 0;
		return 0;
	}
	if (bt.left().empty() && bt.right().empty()) {
		dragones = 0;
		return bt.root();
	}

	int di, dd;
	int ci = mejorCamino(bt.left(), di);
	int cd = mejorCamino(bt.right(), dd);
	dragones = bt.root() == 1 ? 1 : 0;

	if (ci == 0) {
		dragones += dd;
		return cd;
	}
	if (cd == 0) {
		dragones += di;
		return ci;
	}
	if (dd < di) {
		dragones += dd;
		return cd;
	}
	else {
		dragones += di;
		return ci;
	}
}

int mejorCamino(bintree<int> bt) {
	int aux;
	return mejorCamino(bt, aux);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {	
	bintree<int> arbol = leerArbol(-1);

	cout << mejorCamino(arbol) << '\n';
}

int main() {
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; i++)
		resuelveCaso();
		

	return 0;
}
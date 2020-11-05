// Grupo XYZ, Fulano y Mengano
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <vector>
#include <fstream>
#include <memory>
#include <stdexcept>
#include <algorithm>
#include <string>
#include "bintree_eda.h"

using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

int tramosNavegables(bintree<int> rio, int & caudal) {
	if (rio.empty()) {
		caudal = 0;
		return 0;
	}
	if (rio.left().empty() && rio.right().empty()) {
		caudal = 1;
		return 0;
	}
	int caudalIzq, caudalDer;
	int navegablesIzq = tramosNavegables(rio.left(), caudalIzq);
	int navegablesDer = tramosNavegables(rio.right(), caudalDer);

	caudal = caudalIzq + caudalDer - rio.root();
	if (caudal < 0) caudal = 0;

	if (caudal >= 3) return navegablesIzq + navegablesDer + 1;
	else return navegablesIzq + navegablesDer;
}

int tramosNavegables(bintree<int> rio) {
	int caudal = 0;
	int tNav = tramosNavegables(rio, caudal);
	return caudal >= 3 ? tNav - 1 : tNav;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
 void resuelveCaso() {
	 bintree<int> rio = leerArbol<int>(-1);

	 cout << tramosNavegables(rio) << '\n';
}
int main() {
	int nCasos;
	cin >> nCasos;
	for (int i = 0; i < nCasos; i++)
		resuelveCaso();

	return 0;
}
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
bool esZurdo(bintree<char> bt, int & nodos) {	
	if (bt.empty()) {
		nodos = 0;
		return true;
	}
	if (bt.left().empty() && bt.right().empty()) {
		nodos = 1;
		return true;
	}

	int hi, hd = 0;
	bool zi = esZurdo(bt.left(), hi), zd;
	if(zi)
		zd = esZurdo(bt.right(), hd);
	nodos = hi + hd + 1;

	return zi && zd && hi > hd;
}

bool esZurdo(bintree<char> bt) {
	int aux;
	return esZurdo(bt, aux);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {	
	bintree<char> arbol = leerArbol('.');

	string respuesta = esZurdo(arbol) ? "SI" : "NO";
	cout << respuesta << '\n';
}

int main() {
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; i++)
		resuelveCaso();
		

	return 0;
}
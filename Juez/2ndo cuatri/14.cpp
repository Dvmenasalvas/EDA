// Grupo XYZ, Fulano y Mengano
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <algorithm>
#include <string>
#include "bintree_eda.h"

using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

int gruposRescate(bintree<int> montania, int & maximo){
	if(montania.empty()) return 0;
	else{
		int gIzq, gDer, maxIzq = 0, maxDer = 0;
		gIzq = gruposRescate(montania.left(), maxIzq);
		gDer = gruposRescate(montania.right(), maxDer);

		if(gIzq == 0 && gDer == 0){
			if(montania.root() == 0) return 0;
			else {
				maximo = montania.root();
				return 1;
			}
		}
		else {
			maximo = montania.root() + max(maxIzq, maxDer);
			return gIzq + gDer;
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
 void resuelveCaso() {
	 bintree<int> montania = leerArbol(-1);
	 int max = 0;
	 cout << gruposRescate(montania, max) << " ";
	 cout << max << '\n';
}
int main() {
	int casos;
	cin >> casos;
	for(int i = 0; i < casos; i++)
		resuelveCaso();

	return 0;
}
// Grupo XYZ, Fulano y Mengano
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <algorithm>
#include "Polinomio.h"
using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

void resolver() {
	
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	monomio m;
	cin >> m;

	if (!std::cin) // fin de la entrada
		return false;
	polinomio p;
	while (!m.nulo()) {
		p.aniadirM(m);
		cin >> m;
	}//5 6 4 4 6 7 0 0
	int valores, v;
	cin >> valores;
	
	for (int i = 0; i < valores; i++) {
		cin >> v;
		cout << p.evaluar(v) << " ";
	}
	cout << '\n';

	return true;
}
int main() {
	while (resuelveCaso());

	return 0;
}

/*
3 2 6 1 2 0 0 0
2
-2 2
5 1 8 0 0 0
3
5 0 -1
1 5 8 3 4 0 0 0
2
2 3
*/
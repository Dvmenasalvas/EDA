// Daniel Valverde Menasalvas
// Comentario general sobre la soluci�n,
// explicando c�mo se resuelve el problema
#include <iostream>
#include "ThreeMap_eda.h"
using namespace std;

// funci�n que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
template<class Clave, class Valor>
bool keyInBounds(map<Clave, Valor> const& m, Clave const& k) {
	return m.keyInBounds(k);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuraci�n, y escribiendo la respuesta
bool resuelveCaso() {
	map<int, int> m;
	int entrada;
	cin >> entrada;
	while (entrada != -1) {
		m[entrada];
		cin >> entrada;
	}

	cin >> entrada;
	cout << keyInBounds(m, entrada) << '\n';

	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
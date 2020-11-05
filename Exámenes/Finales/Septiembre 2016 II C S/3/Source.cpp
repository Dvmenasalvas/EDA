// Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <vector>
#include <string>
#include "deque_ext.h"
using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	string entrada;
	cin >> entrada;

	deque_ext<string> l1, l2;
	while (entrada != ".") {
		l1.push_back(entrada);
		cin >> entrada;
	}
	cin >> entrada;
	while (entrada != ".") {
		l2.push_back(entrada);
		cin >> entrada;
	}

	string v1, v2, v3;
	cin >> v1 >> v2 >> v3;
	l1.splice(l2, v1, v2, v3);

	l1.print();
	l2.print();

	cout << l1.size() << " " << l2.size();
	
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
// Daniel Valverde Menasalvas
// Comentario general sobre la soluci�n,
// explicando c�mo se resuelve el problema
#include <iostream>
#include <vector>
#include "queue_ext.h"
using namespace std;

// funci�n que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...


// Resuelve un caso de prueba, leyendo de la entrada la
// configuraci�n, y escribiendo la respuesta
bool resuelveCaso() {
	int entrada;
	queue_ext<int> i;
	cin >> entrada;
	while (entrada != -1) {
		i.push(entrada);
		cin >> entrada;
	}
	int a, b;
	cin >> a >> b;

	i.cuela(a, b);
	i.print();

	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
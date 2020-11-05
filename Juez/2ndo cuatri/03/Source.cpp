// Grupo XYZ, Fulano y Mengano
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <algorithm>
#include "Complejo.h"
using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
template<class T>
bool converge(complejo<T> c, int iteraciones) {
	int i = 0;
	complejo<T> z;
	while (z.mod() <= 2 && i < iteraciones) {
		z = z * z + c;
		i++;
	}
	if (i == iteraciones) return true;
	else return false;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	complejo<float> c;
	cin >> c;
	int iteraciones;
	cin >> iteraciones;

	if (converge(c, iteraciones)) cout << "SI\n";
	else cout << "NO\n";
}
int main() {
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; i++)
		resuelveCaso();

	return 0;
}

/*
2
-1.80 -0.40 400
0.20 -0.20 400

*/
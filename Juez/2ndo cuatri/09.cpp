// Grupo XYZ, Fulano y Mengano
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <algorithm>
#include <string>

using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
int resuelveCaso() {
	int hijos;
	cin >> hijos;
	if (hijos == 0) return 1;
	if (hijos == 1) return 1 + resuelveCaso();
	int max = resuelveCaso();
	for (int i = 1; i < hijos; i++) {
		int act = resuelveCaso();
		if (act > max) max = act;
	}
	return max + 1;
}
int main() {
	int nCasos;
	cin >> nCasos;
	for (int i = 0; i < nCasos; i++) {
		cout << resuelveCaso() << '\n';
	}

	return 0;
}

/*
2453/*+
6
811-/
11-8/
00/
*/
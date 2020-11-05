// Grupo XYZ, Fulano y Mengano
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <algorithm>
#include <string>
#include "persona.h"
#include "list_08.h"

using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int nPersonas, min, max;
	cin >> nPersonas >> min >> max;

	if (nPersonas == 0 && min == 0 && max == 0)
		return false;

	list_08<persona> personas;
	persona entrada;
	for (int i = 0; i < nPersonas; i++) {
		cin >> entrada;
		personas.push_back(entrada);
	}

	personas.remove_if([min, max](persona p) {
		return p.getEdad() < min || max < p.getEdad();
		});

	cout << personas;
	cout << "---" << '\n';

	return true;
}
int main() {
	while (resuelveCaso());

	return 0;
}

/*
2453/*+
6
811-/
11-8/
00/
*/
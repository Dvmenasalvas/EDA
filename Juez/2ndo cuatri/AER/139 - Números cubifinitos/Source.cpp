// Grupo XYZ, Fulano y Mengano
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <algorithm>
#include "Cubifinito.h"
using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

void resolver(cubifinito &c) {
	c.esCubifinito();
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	cubifinito c; 
	cin >> c;

	if (c == 0)
		return false;

	resolver(c);

	return true;
}
int main() {
	while (resuelveCaso());

	return 0;
}

/*
4 2
06:40:30 12:50:00 19:20:00 21:25:00
10:20:00
22:00:00
6 3
00:00:00 09:30:00 16:40:30 17:00:00 20:10:40 22:35:00
20:10:40
08:62:30
08:40:30
0 0
*/
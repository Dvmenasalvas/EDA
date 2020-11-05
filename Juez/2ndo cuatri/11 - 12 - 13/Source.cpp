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
#include "bintree_11.h"

using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
 bool resuelveCaso() {
	 char tipo;
	 cin >> tipo;

	 if (!cin)
		 return false;

	 if (tipo == 'N') {
		 bintree_11<int> numeros = leerArbolExt(-1);
		 cout << numeros.getMin() << '\n';
	 }
	 else {
		 string vacio = "#";
		 bintree_11<string> palabras = leerArbolExt(vacio);
		 cout << palabras.getMin() << '\n';
	 }

	return true;
}
int main() {
	while (resuelveCaso());

	return 0;
}
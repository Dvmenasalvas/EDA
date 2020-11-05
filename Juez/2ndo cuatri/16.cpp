// Grupo XYZ, Fulano y Mengano
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <vector>
#include <fstream>
#include <memory>
#include <stdexcept>
#include <algorithm>
#include <string>
#include "bintree_eda.h"

using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

bool esPrimo(int p) {
	if (p < 2) return false;
	for (int i = 2; i <= sqrt(p); i++)
		if (p % i == 0) return false;

	return true;
}

bool multiplo7(int n) {
	return n % 7 == 0 && n != 7;
}

int resuelve(bintree<int> numeros, int & profundidad) { // -1 no hay numeros que valgan
	if (numeros.empty()) {
		profundidad = 0;
		return 0;
	}
	if (numeros.left().empty() && numeros.right().empty()) {
		if (multiplo7(numeros.root())) {
			profundidad = 1;
			return numeros.root();
		}
		profundidad = 0;
		return 0;
	}

	//Caso recursivo
	if (multiplo7(numeros.root())) {
		profundidad = 1;
		return numeros.root();
	}

	if (esPrimo(numeros.root())) {
		profundidad = 0;
		return 0;
	}

	int profundidadDer = 0, profundidadIzq = 0;
	int izq = resuelve(numeros.left(), profundidadIzq);
	int der = resuelve(numeros.right(), profundidadDer);

	if(izq != 0 && der != 0){
		if (profundidadDer < profundidadIzq) {
			profundidad = profundidadDer + 1;
			return der;
		} else {
			profundidad = profundidadIzq + 1;
			return izq;
		}
	}
	if (izq != 0) {
		profundidad = profundidadIzq + 1;
		return izq;
	}
	if (der != 0) {
		profundidad = profundidadDer + 1;
		return der;
	}

	profundidad = 0;
	return 0;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
 void resuelveCaso() {
	 bintree<int> numeros = leerArbol<int>(-1);
	 int profundidad;
	 int resultado = resuelve(numeros, profundidad);
	 if (resultado == 0) cout << "NO HAY" << '\n';
	 else cout << resultado << " " << profundidad <<'\n';
}

int main() {
	int nCasos;
	cin >> nCasos;
	for (int i = 0; i < nCasos; i++)
		resuelveCaso();

	return 0;
}
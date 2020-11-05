// Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include "GestionAdmisiones.h"
using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	unordered_map<int, int> mapa;
	mapa.insert({ 1,1 });
	mapa.insert({ 2 , 2 });
	mapa.insert({ 3 , 3 });
	for (auto it : mapa) {
		cout << it.second << " ";
	}
	return false;
}
int main() {
	while (resuelveCaso());
	return 0;
}
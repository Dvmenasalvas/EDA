// Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include "set_modificado.h"
using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int n;
	cin >> n;

	if (!cin)
		return false;

	set<int> a;
	int entrada;
	for (int i = 0; i < n; i++) {
		cin >> entrada;
		a.insert(entrada);
	}
	while (entrada != 0) {
		cin >> entrada;
		auto sol = a.lower_bound(entrada);
		cout << sol.first << " " << sol.second << '\n';
	}
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
// Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <vector>
using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

bool esBusqueda(int ini, int fin, vector<int> const & v, int &max, int & min) {
	if (ini == fin) return true;
	if (ini == fin - 1) {
		min = v[ini];
		max = min;
		return true;
	}

	int mid = (ini + fin) / 2 + 1;
	bool l, r;
	int maxl, maxr, minl, minr;
	l = esBusqueda(ini + 1, mid, v, maxl, minl);
	min = minl;
	if (l) {
		r = esBusqueda(mid, fin, v, maxr, minr);
		max = maxr;
	}

	return l && r && maxl < v[ini] && v[ini] < minr;
}

bool esBusqueda(vector<int> const & v) {
	int max = 0, min = 0;
	return esBusqueda(0, v.size(), v, max, min);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	vector<int> v;
	int entrada;
	cin >> entrada;
	while (entrada != -1) {
		v.push_back(entrada);
		cin >> entrada;
	}

	cout << esBusqueda(v) << '\n';

	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
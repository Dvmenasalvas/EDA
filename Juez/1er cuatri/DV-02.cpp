// Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <vector>
using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int DV(int ini, int fin, vector<int> const & a) {
	if (ini == fin - 1) return a[ini];
	if (ini == fin - 2) return a[ini] < a[ini + 1] ? a[ini] : a[ini + 1];

	int mid = (ini + fin) / 2;
	if (a[mid - 1] < a[mid]) return DV(ini, mid, a);
	else return DV(mid, fin, a);
}int DV(vector<int> const & a) {	return DV(0, a.size(), a);}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int n;
	cin >> n;

	if (!cin)
		return false;

	vector<int> a;
	int entrada;
	for (int i = 0; i < n; i++) {
		cin >> entrada;
		a.push_back(entrada);
	}
	
	cout << DV(a) << '\n';
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
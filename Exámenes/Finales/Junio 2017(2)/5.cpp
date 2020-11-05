// Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <vector>
using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int DV(int ini, int fin, vector<int> const & a, vector<int> const & b) {
	if (ini == fin - 1) return ini;
	if (ini == fin - 2) return a[ini] == b[ini] ? ini + 1 : ini;
	
	int mid = (fin + ini) / 2;
	if (a[mid - 1] == b[mid - 1]) return DV(mid, fin, a, b);
	else return DV(ini, mid, a, b);
}int DV(vector<int> const & a, vector<int> const& b) {	return DV(0, a.size(), a, b);}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int n;
	cin >> n;

	if (n == 0 )
		return false;

	vector<int> a, b;
	int entrada;
	for (int i = 0; i < n; i++) {
		cin >> entrada;
		a.push_back(entrada);
	}
	
	for (int i = 0; i < n - 1; i++) {
		cin >> entrada;
		b.push_back(entrada);
	}

	cout << DV(a, b) << '\n';
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
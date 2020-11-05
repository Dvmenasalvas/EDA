// Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <vector>
using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

int resolver(vector<int> const& a) {
	if (a.size() <= 2) return a.size();

	int act = 2, max = 2;
	int primero = a[0], segundo = a[1];
	for (int i = 2; i < a.size(); i++) {
		if (primero + segundo == a[i]) {
			act++;
		}
		else {
			if (act > max) max = act;
			act = 2;
		}
		primero = segundo;
		segundo = a[i];
	}
	if (act > max) max = act;
	return max;
}

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
	cout << resolver(a) << '\n';
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
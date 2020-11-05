// Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <vector>
using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int beneficio(vector<int> a, vector<int> b) {
	int menores = 0, iguales = 0, primeroMayor = 0, total = 0;

	for (int i = 0; i < a.size(); i++) {
		if (i == 0 || a[i] > a[i - 1]) {
			menores += iguales;
			iguales = 0;
			while (primeroMayor < b.size() && a[i] > b[primeroMayor]) {
				menores++;
				primeroMayor++;
			}
			while (primeroMayor < b.size() && a[i] == b[primeroMayor]) {
				iguales++;
				primeroMayor++;
			}
		}
		total += menores * (b.size() - menores - iguales);
	}
	return total;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int n, m;
	cin >> n >> m;

	if (n == 0 && m == 0)
		return false;

	vector<int> a, b;
	int entrada;
	for (int i = 0; i < n; i++) {
		cin >> entrada;
		a.push_back(entrada);
	}
	
	for (int i = 0; i < m; i++) {
		cin >> entrada;
		b.push_back(entrada);
	}

	cout << beneficio(a, b) << '\n';
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
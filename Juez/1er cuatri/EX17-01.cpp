// Grupo XYZ, Fulano y Mengano
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <vector>
using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
bool resolver(vector<int> numeros, int d) {
	bool correcto = true;
	int i = 1, actual = 1;
	while (i < numeros.size() && correcto) {
		if (numeros[i] == numeros[i - 1]) {
			if (actual + 1 <= d)
				actual++;
			else correcto = false;
		}
		else if (numeros[i] == numeros[i - 1] + 1)
			actual = 1;
		else correcto = false;
		i++;
	}
	return correcto;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int d, n, entrada;
	cin >> d >> n;
	vector<int> numeros;
	for (int i = 0; i < n; i++) {
		cin >> entrada;
		numeros.push_back(entrada);
	}
	if (resolver(numeros, d)) cout << "SI" << '\n';
	else cout << "NO" << '\n';
}
int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}

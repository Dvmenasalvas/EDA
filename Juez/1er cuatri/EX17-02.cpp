// Grupo XYZ, Fulano y Mengano
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <vector>
using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

bool porPelos(int a, int b) {
	return a == b || a == b - 1;
}

bool resolverAux(vector<int> numeros, int ini, int fin) {
	if (fin - ini == 1 || fin - ini == 0) return true;
	else if (fin - ini == 2) return porPelos(numeros[ini], numeros[ini + 1]);
	else {
		int mitad = ini + (fin - ini) / 2;
		if (numeros[mitad] <= numeros[ini] + (mitad - ini) && porPelos(numeros[mitad - 1], numeros[mitad]))
			return resolverAux(numeros, ini, mitad) && resolverAux(numeros, mitad, fin);
		else return false;
	}
}

bool resolver(vector<int> numeros) {
	return resolverAux(numeros, 0, numeros.size());
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int n, entrada;
	cin >> n;
	vector<int> numeros;
	for (int i = 0; i < n; i++) {
		cin >> entrada;
		numeros.push_back(entrada);
	}
	if (resolver(numeros)) cout << "SI" << '\n';
	else cout << "NO" << '\n';
}
int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}

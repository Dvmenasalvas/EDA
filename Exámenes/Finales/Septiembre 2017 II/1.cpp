// Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <vector>
using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

int sumaID(vector<int> const& v) {
	int der = 0, izq = 0;
	for (int i = 0; i < v.size(); i++)
		der += v[i];

	int res = 0;
	int i = 0;
	der -= v[i];
	while (izq < der) {
		izq += v[i];
		i++;
		der -= v[i];
		res++;
	}
	return res;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int M;
	cin >> M;

	if (!cin)
		return false;
	
	vector<int> w;
	int entrada;
	for (int i = 0; i < M; i++) {
		cin >> entrada;
		w.push_back(entrada);
	}

	cout << sumaID(w) << '\n';

	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
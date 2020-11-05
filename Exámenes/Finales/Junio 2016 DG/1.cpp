// Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <vector>
using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

bool resolver(vector<int> const& w, vector<int> const& v){
	int i = 0, j = 0;
	bool res = true;
	while (res && i < w.size()) {
		while (v[j] < w[i] && j < v.size()) 
			j++;
		res = v[j] == w[i];
		i++;
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

	int N;
	cin >> N;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		cin >> entrada;
		v.push_back(entrada);
	}
	cout << resolver(v, w) << '\n';

	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
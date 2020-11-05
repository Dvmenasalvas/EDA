// Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <vector>
using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

int resolver(int ini, int fin, vector<int> const& w, int dif) {
	if (ini == fin - 2)	return w[ini] + dif;

	int mid = (ini + fin) / 2;
	if (w[mid] == w[0] + mid * dif) return resolver(mid, fin, w, dif);
	else return resolver(ini, mid + 1, w, dif);
}

int resolver(vector<int> const& w, int diferencia){
	return resolver(0, w.size(), w, diferencia);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int M;
	cin >> M;

	if (!cin)
		return false;
	
	int dif;
	cin >> dif;
	vector<int> w;
	int entrada;
	for (int i = 0; i < M; i++) {
		cin >> entrada;
		w.push_back(entrada);
	}

	cout << resolver(w,dif) << '\n';

	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
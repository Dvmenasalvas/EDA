// Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <unordered_map>
using namespace std;

void printear(vector<int> const& sol) {
	for (int i = 0; i < sol.size(); i++)
		cout << sol[i];
	cout << '\n';
}

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

void timidos(int k, int const& N, vector<int> &sol, int const& ini, int const& fin, vector<int> & usados) {
	int initLim = k > 0 ? sol[k - 1] : ini;
	for (int i = initLim; i <= fin; i++) {
		//Caso valido
		if (usados[i - ini] < i) {
			//Marcamos
			usados[i - ini]++;
			//Tratamos
			sol[k] = i;
			if (k < N - 1) timidos(k + 1, N, sol, ini, fin, usados);
			else printear(sol);
			//Desmarcamos
			usados[i - ini]--;
		}
	}
}

void timidos(int n, int ini, int fin) {
	vector<int> usados(fin - ini + 1), sol(n);
	timidos(0, n,sol, ini, fin, usados);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int n;
	cin >> n;

	if (!cin)
		return false;

	int ini, fin;
	cin >> ini >> fin;
	timidos(n, ini, fin);
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
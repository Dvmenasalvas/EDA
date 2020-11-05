// Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <vector>
using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

bool jaque(vector<int> const & sol, int k){
	int i = 0;
	bool jaque = false;
	while (i != k  && !jaque){
		jaque = (sol[k] == sol[i]) || (abs(sol[k] - sol[i]) == k - i);
		i++;
	}
	return jaque;
}

void reinasVA1(vector<int> & sol, int k, int N, int & soluciones){
	for (int j = 0; j < N; j++){
		sol[k] = j;
		if (!jaque(sol, k)){
			if (k == N - 1) soluciones++;
			else reinasVA1(sol, k + 1, N, soluciones);
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int N;
	cin >> N;

	int soluciones = 0;
	vector<int> sol(N);
	reinasVA1(sol, 0, N, soluciones);
	cout << soluciones << '\n';

}
int main() {
	int repes;
	cin >> repes;
	for (int i = 0; i < repes; i++)
		resuelveCaso();
	return 0;
}
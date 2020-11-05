// Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <vector>
#include <string>
using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

void reinasTorresVA(int k, int R, int  r, int T, int t, int & soluciones, vector<bool> & C, vector<int>& D) {
	for (int j = 0; j < T + R; j++) {
		//Reina
		if (r < R) {
			if (!C[j] && D[T + R - 1 + j - k] == 0 && D[2 * (T + R) - 1 + j + k] == 0) {//Es solución?
				//Marcamos
				C[j] = true;
				int diago1 = D[T + R - 1 + j - k];
				int diago2 = D[2 * (T + R) - 1 + j + k];
				D[T + R - 1 + j - k] = 2; 
				D[2 * (T + R) - 1 + j + k] = 2;
				//Seguimos
				if (k == T + R - 1) soluciones++;
				else (reinasTorresVA(k + 1, R, r + 1, T, t, soluciones, C, D));
				//Desmarcamos
				D[T + R - 1 + j - k] = diago1;
				D[2 * (T + R) - 1 + j + k] = diago2;
				C[j] = false;
			}
		}
		//Torreb
		if (t < T) {
			if (!C[j] && D[T + R - 1 + j - k] <= 1 && D[2 * (T + R) - 1 + j + k] <= 1) {//Es solución?
				//Marcamos
				C[j] = true;
				int diago1 = D[T + R - 1 + j - k];
				int diago2 = D[2 * (T + R) - 1 + j + k];
				D[T + R - 1 + j - k] = 1;
				D[2 * (T + R) - 1 + j + k] = 1;
				//Seguimos
				if (k == T + R - 1) soluciones++;
				else (reinasTorresVA(k + 1, R, r, T, t + 1, soluciones, C, D));
				//Desmarcamos
				D[T + R - 1 + j - k] = diago1;
				D[2 * (T + R) - 1 + j + k] = diago2;
				C[j] = false;
			}
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int T, R;
	cin >> T >> R;
	
	if ( T == 0 && R == 0) return false;

	vector<int> D(4*(T + R) -2);
	for (int i = 0; i < D.size(); i++)
		D[i] = 0;
	vector<bool> C(T + R);
	for (int i = 0; i < C.size(); i++)
		C[i] = false;
	int soluciones = 0;
	int r = 0, t = 0;
	reinasTorresVA(0, R, r, T, t, soluciones,C,D);
	cout << soluciones << '\n';
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
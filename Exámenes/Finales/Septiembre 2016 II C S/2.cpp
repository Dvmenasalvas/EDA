// Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <vector>
using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

void funcionarios(int k,  int &t, int& mejorT, int & minimo, vector<int> const& minimos,
	vector<bool>& usados, vector<vector<int>> const & v) {
	minimo -= minimos[k];
	for (int i = 0; i < v.size(); i++) {
		if (!usados[i]) {
			//Marcamos
			usados[i] = true;
			t += v[i][k];
			//Tratamos
			if (k == v.size() - 1) {
				if (t < mejorT)
					mejorT = t;
			}
			else if (t + minimo < mejorT)
				funcionarios(k + 1, t, mejorT, minimo, minimos, usados, v);
			//Desmarcamos
			usados[i] = false;
			t -= v[i][k];
		}
	}
	minimo += minimos[k];
}

int funcionarios(vector<vector<int>> const & v) {
	vector<bool> usados(v.size());
	for (int i = 0; i < v.size(); i++)
		usados[i] = false;

	vector<int> minimos;
	int mejorT = 0;
	int minimo = 0;
	for (int j = 0; j < v.size(); j++) {
		mejorT += v[j][j];
		int min = v[0][j];
		for (int i = 1; i < v.size(); i++) {
			if (v[i][j] < min)
				min = v[i][j];
		}
		minimos.push_back(min);
		minimo += min;
	}

	int t = 0;
	funcionarios(0, t, mejorT,minimo, minimos, usados, v);
	return mejorT;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int n;
	cin >> n;
	
	if (n == 0)
		return false;

	vector<vector<int>> v(n);	//[funcionario][trabajo]
	int entrada;
	for(int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> entrada;
			v[i].push_back(entrada);
		}
	}
	

	cout << funcionarios(v) << '\n';

	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
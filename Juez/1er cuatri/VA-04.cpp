// Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <vector>
using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

void funcionariosVA(int k, int &valor, int &mejorValor, vector<vector<int>> const & funcionarios, vector<bool> &asignado, vector<int> const & minimos, int &cotaInferior) {
	for (int j = 0; j < funcionarios.size(); j++) {
		if (!asignado[j]) {
			valor += funcionarios[k][j];
			cotaInferior -= minimos[j];
			if (valor + cotaInferior < mejorValor) {
				//Marcamos
				asignado[j] = true;
				//Tratamos
				if (k == funcionarios.size() - 1) mejorValor = valor;
				else funcionariosVA(k + 1, valor, mejorValor, funcionarios, asignado, minimos, cotaInferior);
				//Desmarcamos
				asignado[j] = false;
			}
			cotaInferior += minimos[j];
			valor -= funcionarios[k][j];
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int N;
	cin >> N;
	vector<vector<int>> funcionarios;
	for (int i = 0; i < N; i++) {
		vector<int> funcionario;
		int entrada;
		for (int j = 0; j < N; j++) {
			cin >> entrada;
			funcionario.push_back(entrada);
		}
		funcionarios.push_back(funcionario);
	}

	if (N == 0) return false;

	vector<bool> asignado(N);
	int valor = 0, mejorValor = 0;
	for (int i = 0; i < N; i++) {
		asignado[i] = false;				//Ponemos asignados en false	
		mejorValor += funcionarios[i][i];	//Damos un valor factible para poder comparar desde el principio
	}
	vector<int> minimos;
	int cotaInferior = 0;
	for (int j = 0; j < N; j++) {
		int minimo = funcionarios[0][j];
		for (int i = 1; i < N; i++)
			if (funcionarios[i][j] < minimo) minimo = funcionarios[i][j];
		minimos.push_back(minimo);
		cotaInferior += minimo;
	}
	funcionariosVA(0, valor, mejorValor, funcionarios, asignado, minimos, cotaInferior);
	cout << mejorValor << '\n';
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
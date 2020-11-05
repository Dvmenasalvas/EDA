// Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <vector>
#include <string>
using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

void printear(vector<string> sol) {
	for (int i = 0; i < sol.size(); i++) {
		if (sol[i] == "a")cout << "azul ";
		else if (sol[i] == "r")cout << "rojo ";
		else if (sol[i] == "v")cout << "verde ";
	}
	cout << '\n';
}

void torreVA(int k, vector<string> &sol, bool &solucion, vector<int> &cubos, vector<int> const &maximos, int altura) {
	if (altura / 2 > cubos[0] + cubos[2] + (altura + 1) % 2) {
		//Azul
		if (cubos[0] < maximos[0]) {
			//Apuntamos
			sol[k] = "a";
			//Marcamos
			cubos[0]++;
			//Tratamos
			if (k == altura - 1) {
				printear(sol);
				solucion = true;
			}
			else torreVA(k + 1, sol, solucion, cubos, maximos, altura);
			//Desmarcamos
			cubos[0]--;
		}
	}
	//Rojo
	if (cubos[1] < maximos[1]) {
		//Apuntamos
		sol[k] = "r";
		//Marcamos
		cubos[1]++;
		//Tratamos
		if (k == altura - 1) {
			printear(sol);
			solucion = true;
		}
		else torreVA(k + 1, sol, solucion, cubos, maximos, altura);
		//Desmarcamos
		cubos[1]--;
	}
	if (altura / 2 > cubos[0] + cubos[2] + (altura + 1) % 2) {
		//Verde
		if (cubos[2] < maximos[2] && sol[k - 1] != "v" && cubos[2] < cubos[0]) {
			//Apuntamos
			sol[k] = "v";
			//Marcamos
			cubos[2]++;
			//Tratamos
			if (k == altura - 1) {
				printear(sol);
				solucion = true;
			}
			else torreVA(k + 1, sol, solucion, cubos, maximos, altura);
			//Desmarcamos
			cubos[2]--;
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int altura, A, R, V;
	vector<int> maximos;
	cin >> altura >> A >> R >> V;
	maximos.push_back(A);
	maximos.push_back(R);
	maximos.push_back(V);

	if ( altura == 0 && A == 0 && R == 0 && V == 0) return false;

	vector<string> sol(altura);
	sol[0] = "r";
	bool solucion = false;
	vector<int> cubos(3); // [0]Azul [1]Rojo [2]Verde
	cubos[0] = 0;
	cubos[1] = 1;
	cubos[2] = 0;
	torreVA(1, sol, solucion, cubos, maximos, altura);
	if (!solucion) cout << "SIN SOLUCION" << '\n';
	cout << '\n';
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
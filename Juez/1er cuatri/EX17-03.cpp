// Grupo XYZ, Fulano y Mengano
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <vector>
using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

void printear(vector<int> const & solucion) {
	for (int i = 0; i < solucion.size(); i++)
		cout << solucion[i] << " ";
	cout << '\n';
}

void escribeCPD(int k, vector<int> & solucion, int &actual, int d) {
	//Ponemos el mismo numero
	if (actual < d) {
		//Marcamos
		solucion[k] = solucion[k - 1];
		actual++;
		//Tratamos
		if (k == solucion.size() - 1) printear(solucion);
		else escribeCPD(k + 1, solucion, actual, d);
		//Desmarcamos
		actual--;
	}
	//Ponemos el siguiente numero
	//Marcamos
	int aux = actual;
	actual = 1;
	solucion[k] = solucion[k - 1] + 1;
	//Tratamos
	if (k == solucion.size() - 1) printear(solucion);
	else escribeCPD(k + 1, solucion, actual, d);
	//Desmarcar
	actual = aux;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int n, d, e;
	cin >> n >> d >> e;
	if (n == 1) cout << e << '\n';
	else if (n > 1) {
		vector<int> solucion(n);
		solucion[0] = e;
		int actual = 1;
		escribeCPD(1, solucion, actual, d);
	}
}
int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}

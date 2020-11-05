// Grupo XYZ, Fulano y Mengano
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <vector>
#include <fstream>
#include <memory>
#include <stdexcept>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {	//O(N) lineal en el numero de capítulos
	unordered_map<int, int> capitulos;
	int n, capitulo;
	int max = 0, act = 1, ultRepe = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> capitulo;
		if (act - std::max(ultRepe, capitulos[capitulo]) > max)
			max = act - std::max(ultRepe, capitulos[capitulo]);
		if(capitulos[capitulo] > ultRepe) ultRepe = capitulos[capitulo];

		capitulos[capitulo] = act;
		act++;
	}
	if (act - 1 - ultRepe > max) max = act - 1 - ultRepe;

	cout << max << '\n';

}

int main() {
	int nCasos;
	cin >> nCasos;
	for (int i = 0; i < nCasos; i++)
		resuelveCaso();

	return 0;
}
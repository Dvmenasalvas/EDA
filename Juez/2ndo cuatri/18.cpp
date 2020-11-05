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
#include <map>
#include <sstream>

using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

void pintar(map<string, int> m, string ini) {
	if (m.size() > 0) {
		cout << ini;
		for (auto p : m) {
			cout << " " << p.first;
		}
		cout << '\n';
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	map<string, int> antiguo;

	string linea;
	getline(cin, linea);
	stringstream ss(linea);
	string palabra;
	int valor;

	while (ss >> palabra) {
		ss >> valor;
		antiguo[palabra] = valor;
	}
	getline(cin, linea);
	map<string, int> mas, cambio;
	stringstream ss2(linea);
	while (ss2 >> palabra) {
		ss2 >> valor;
		if (antiguo.count(palabra)) {
			if (antiguo[palabra] != valor)
				cambio[palabra];
		}
		else mas[palabra];
		antiguo.erase(palabra);
	}
	pintar(mas, "+");
	pintar(antiguo, "-");
	pintar(cambio, "*");
	if (mas.size() == 0 && antiguo.size() == 0 && cambio.size() == 0)
		cout << "Sin cambios" << '\n';
	cout << "----" << '\n';
}

int main() {
	int nCasos;
	cin >> nCasos;
	string linea;
	getline(cin, linea);
	for (int i = 0; i < nCasos; i++)
		resuelveCaso();

	return 0;
}
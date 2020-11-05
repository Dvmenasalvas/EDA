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

void pintar(map<string, vector<int>> diccionario) {
	for (auto par : diccionario) {
		cout << par.first;
		for (int i = 0; i < par.second.size(); i++)
			cout << " " << par.second[i];
		cout << '\n';
	}
	cout << "----\n";
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {	//O(NlogN) en el numero de palabras
	int N;
	cin >> N;

	if (N == 0)
		return false;
	
	map<string, vector<int>> diccionario;
	string linea;
	getline(cin, linea);
	for (int i = 1; i <= N; i++) {
		getline(cin, linea);
		stringstream ss(linea);
		string palabra;
		while (ss >> palabra) {
			transform(palabra.begin(), palabra.end(), palabra.begin(), ::tolower);
			if (palabra.length() > 2)
				if (diccionario[palabra].size() == 0)
					diccionario[palabra].push_back(i);
				else if (diccionario[palabra][diccionario[palabra].size() - 1] != i)
					diccionario[palabra].push_back(i);
		}
	}

	pintar(diccionario);

	return true;
}

int main() {
	while (resuelveCaso()) {}
		

	return 0;
}
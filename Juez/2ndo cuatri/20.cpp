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
#include <ctype.h>
#include <queue>
using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

bool isSport(string s) {
	string aux = s;
	for (char &c : aux) {
		c = toupper(c);
	}
	return aux == s;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {	//O(N) lineal en el numero de capítulos
	string deporte;

	cin >> deporte;

	if (!cin)
		return false;

	unordered_map<string, string> personas;
	unordered_map <string, int> deportes;

	string nick;
	deportes[deporte];
	while (deporte != "_FIN_") {
		cin >> nick;
		if (!isSport(nick)) {
			if (personas.count(nick)) {
				if (personas[nick] != deporte && personas[nick] != "borrado") {
					deportes[personas[nick]]--;
					personas[nick] = "borrado";
				}
			}
			else {
				personas[nick] = deporte;
				deportes[deporte]++;
			}
		}
		else {
			deporte = nick;
			if (deporte != "_FIN_")
				deportes[deporte];
		}
	}

	vector<pair<string, int>> deportesOrd;
	for (auto par : deportes)
		deportesOrd.push_back(par);

	sort(deportesOrd.begin(), deportesOrd.end(), [](pair<string, int> a, pair<string, int> b) {
		if (a.second != b.second)
			return (a.second > b.second);
		else
			return (a.first < b.first);
	});

	for (auto dep : deportesOrd) {
		cout << dep.first << " " << dep.second << '\n';
	}
	cout << "***\n";

	return true;
}

int main() {
	while (resuelveCaso()) {
	}


	return 0;
}
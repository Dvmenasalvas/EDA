// Grupo XYZ, Fulano y Mengano
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <algorithm>
#include "Hora.h"
using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

bool siguiente(vector<hora> const & trenes, hora const & h, hora & siguiente) {
	int i = 0;
	while (i < trenes.size() && trenes[i] < h)
		i++;
	if (i < trenes.size()) {
		siguiente = trenes[i];
		return true;
	} else
		return false;
}

void resolver(vector<hora> const &trenes, int horas) {
	hora h;
	for (int i = 0; i < horas; i++) {
		try {
			cin >> h;
			auto pos = lower_bound(trenes.begin(), trenes.end(), h);
			if (pos == trenes.end()) cout << "NO\n";
			else cout << *pos << '\n';
		}
		catch (domain_error e) {
			cout << "ERROR\n";
		}
	}
	cout << "---\n";
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int t, h;
	cin >> t >> h;

	if (t == 0 && h == 0)
		return false;
	
	vector<hora> trenes(t);
	for (auto & ho : trenes) {
		cin >> ho;
	}

	resolver(trenes, h);
	
	return true;
}
int main() {
	while (resuelveCaso());

	return 0;
}

/*
4 2
06:40:30 12:50:00 19:20:00 21:25:00
10:20:00
22:00:00
6 3
00:00:00 09:30:00 16:40:30 17:00:00 20:10:40 22:35:00
20:10:40
08:62:30
08:40:30
0 0
*/
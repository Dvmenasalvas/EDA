// Grupo XYZ, Fulano y Mengano
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <fstream>
#include <string>
#include "Conjunto.h"
using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

void resolver() {

}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	char tipo; int k;
	cin >> tipo >> k;
	
	if (!cin)
		return false;

	if (tipo == 'N') {
		set<int> elementos(k);
		int entrada;
		cin >> entrada;
		while (entrada != -1) {
			elementos.insertK(entrada);
			cin >> entrada;
		}
		cout << elementos;
	}
	else {
		set<string> elementos(k);
		string entrada;
		cin >> entrada;
		while (entrada != "FIN") {
			elementos.insertK(entrada);
			cin >> entrada;
		}
		cout << elementos;
	}

	return true;
}
int main() {
	while (resuelveCaso());

	return 0;
}

/*
N
3
1 8 3 14 5 -1
P
2
maria luis marta juan alberto FIN
N
3
1 2 3 4 5 6 6 6 -1

*/
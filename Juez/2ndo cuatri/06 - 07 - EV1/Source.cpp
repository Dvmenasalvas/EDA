// Grupo XYZ, Fulano y Mengano
// Comentario general sobre la soluci�n,
// explicando c�mo se resuelve el problema
#include <iostream>
#include <fstream>
#include <string>
#include "queue_eda.h"
#include "Queue_06.h"
using namespace std;
// funci�n que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

void resolver() {

}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuraci�n, y escribiendo la respuesta
bool resuelveCaso() {
	queue_06<int> q;
	int entrada;

	cin >> entrada;

	if (!cin)
		return false;

	while (entrada != 0) {
		q.push(entrada);
		cin >> entrada;
	}

	q.invierte();
	q.print();

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
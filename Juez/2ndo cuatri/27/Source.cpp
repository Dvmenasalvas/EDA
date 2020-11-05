// Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include "queue_extendida.h"
#include "queue_eda.h"
using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int N;
	cin >> N;

	if (!cin)
		return false;

	queue_ext<int> a;
	int entrada;
	for (int i = 0; i < N; i++) {
		cin >> entrada;
		a.push(entrada);
	}

	int M, P;
	cin >> M >> P;
	queue<int> q;
	for (int i = 0; i < M; i++) {
		cin >> entrada;
		q.push(entrada);
	}

	a.insertar(q, P);

	a.print();

	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
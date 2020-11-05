// Grupo XYZ, Fulano y Mengano
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <vector>
using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

bool resolverAux(int & peso) {
	int Dd, Di, Pi, Pd;
	cin >> Pi >> Di >> Pd >> Dd;
	if (Pi != 0 && Pd != 0) { //Caso base, no hay submoviles
		peso = Pd + Pi;
		return Pi * Di == Pd * Dd;
	}
	else { //Hay submoviles
		bool izq = true, der = true;
		if (Pi == 0) izq = resolverAux(Pi);
		if (Pd == 0) der = resolverAux(Pd);
		peso = Pi + Pd;
		return izq && der && Pi * Di == Pd * Dd;
	}
}

bool resolver() {
	int peso;
	return resolverAux(peso);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	if (resolver()) cout << "SI" << '\n';
	else cout << "NO" << '\n';
}
int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}

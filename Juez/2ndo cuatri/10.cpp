// Grupo XYZ, Fulano y Mengano
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <algorithm>
#include <string>

using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

int resuelve(int minJefes, int altura = 0) {
	int subordinados;
	cin >> subordinados;
	
	if (subordinados == 0) {
		if (altura >= minJefes) return 1;
		else return 0;
	} else {
		int becarios = 0;
		for (int i = 0; i < subordinados; i++)
			becarios += resuelve(minJefes, altura + 1);
		return becarios;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int minJefes;
	cin >> minJefes;

	if (!cin)
		return false;

	cout << resuelve(minJefes) << '\n';

	return true;
}
int main() {
	while (resuelveCaso());

	return 0;
}

/*
2453/*+
6
811-/
11-8/
00/
*/
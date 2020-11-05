// Grupo XYZ, Fulano y Mengano
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <algorithm>
#include "Hora.h"
#include "Pelicula.h"
using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

void resolver(int pelis) {
	vector<pelicula> peliculas(pelis);
	for (auto & p : peliculas)
		cin >> p;
	sort(peliculas.begin(), peliculas.end());
	for (pelicula p : peliculas)
		cout << p;
	cout << "---\n";
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int pelis;
	cin >> pelis;

	if (pelis == 0)
		return false;
	
	resolver(pelis);
	
	return true;
}
int main() {
	while (resuelveCaso());

	return 0;
}

/*
3
17:40:20 02:20:10 El hombre tranquilo
15:30:00 01:35:40 12 hombres sin piedad
20:40:10 01:55:10 Horizontes lejanos
3
15:10:00 01:20:00 Gremlins
13:10:00 03:20:00 Ben-Hur
12:00:50 00:59:10 La soga
0

*/
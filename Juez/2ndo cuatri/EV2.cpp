// Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <string>
#include "bintree_eda.h"
using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

//O(N) lineal en el número de nodos del arbol en el caso peor( el arbol es de busqueda)
//si el arbol no es de busqueda el algoritmo puede parar antes
bool esBinario(bintree<int> t, int & min, int & max) { 
	if (t.empty()) {	//Esta vacio
		//Ponemos min mas grande que max para determinar que es arbol vacio
		min = 1;		
		max = 0;
		return true;
	}
	if (t.left().empty() && t.right().empty()) {	//Es hoja
		min = t.root();
		max = min;
		return true;
	}
	int maxl = 0, maxr = 0, minl = 0, minr = 0;
	bool binl = esBinario(t.left(), minl, maxl);
	bool binr = false;
	if (binl) binr = esBinario(t.right(), minr, maxr);

	bool right = false, left = false;
	//Si left y right son de busqueda, vemos si encajan bien con la raiz
	if (binl && binr) {
		if (maxl >= minl) { //Left no es vacio
			left = maxl < t.root();
			min = minl;
		}
		else {	//Left vacio
			left = true;
			min = t.root();
		}
		if (maxr >= minr) {	//Right no es vacio
			right = t.root() < minr;
			max = maxr;
		}
		else {	//Right vacio
			right = true;
			max = t.root();
		}
	}

	return binl && binr && right && left;
}

bool esBinario(bintree<int> t) {
	int max, min;
	return esBinario(t, min, max);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {	//O(N) en 
	bintree<int> t = leerArbol(-1);

	string salida = esBinario(t) ? "SI" : "NO";
	cout << salida << '\n';
}

int main() {
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; i++)
		resuelveCaso();


	return 0;
}
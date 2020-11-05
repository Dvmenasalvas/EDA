// Grupo XYZ, Fulano y Mengano
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <algorithm>
#include <string>
#include "stack_eda.h"
#include "queue_eda.h"
using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

int evaluar(char c, int op1, int op2) {
	switch (c) {
	case '+':
		return op1 + op2;
	case '-':
		return op1 - op2;
	case '/':
		if (op2 == 0) throw domain_error("Division por 0");
		return op1 / op2;
	case '*':
		return op1 * op2;
	}
	return 0;
}

bool evaluarPila(string const & expresion, int & resultado) {
	stack<int> pila;
	for (char c : expresion) {
		if (isdigit(c)) {
			pila.push(c - '0');
		} else {
			try {
				int op2 = pila.top(); pila.pop();
				int op1 = pila.top(); pila.pop();
				pila.push(evaluar(c, op1, op2));
			} catch (domain_error e) {
				return false;
			}
		}
	}
	resultado = pila.top();
	return true;
}

bool evaluarCola(string const & expresion, int & resultado) {
	queue<int> cola;
	for (char c : expresion) {
		if (isdigit(c)) {
			cola.push(c - '0');
		}
		else {
			try {
				int op2 = cola.front(); cola.pop();
				int op1 = cola.front(); cola.pop();
				cola.push(evaluar(c, op1, op2));
			}
			catch (domain_error e) {
				return false;
			}
		}
	}
	resultado = cola.front();
	return true;
}

void resolver(string const & expresion) {
	int cola;
	int pila;
	bool evCola = evaluarCola(expresion, cola);
	bool evPila = evaluarPila(expresion, pila);
	if (evPila) cout << pila;
	else cout << "ERROR";
	if (evCola == evPila && (evCola == false || cola == pila)) {
		cout << " = ";
	} else {
		cout << " != ";
	}
	
	if(evCola)	cout << cola;
	else cout << "ERROR";
	cout << '\n';
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	string entrada;
	cin >> entrada;

	if (!cin)
		return false;

	resolver(entrada);

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
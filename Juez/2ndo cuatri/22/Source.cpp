// Grupo XYZ, Fulano y Mengano
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include "autoescuela.h"

using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

void ejecutarAccion(string accion, autoescuela& autoescuela) {
	string p, a;
	int n;
	try {
		if (accion == "alta") {
			cin >> a >> p;
			autoescuela.alta(a, p);
		}
		else if (accion == "es_alumno") {
			cin >> a >> p;
			string salida = autoescuela.esAlumno(a, p) ? " es" : " no es";
			cout << a << salida << " alumno de " << p << '\n';
		}
		else if (accion == "examen") {
			cin >> p >> n;

			vector<string> examinados = autoescuela.examen(p,n);
			cout << "Alumnos de " << p << " a examen:\n";
			for (auto a : examinados) {
				cout << a << '\n';
			}
		}
		else if (accion == "actualizar") {
			cin >> a >> n;
			autoescuela.actualizar(a, n);
		}
		else if (accion == "puntuacion") {
			cin >> a;
			int punt = autoescuela.puntuacion(a);

			cout << "Puntuacion de " << a << ": " << punt << '\n';
		}
		else if (accion == "aprobar") {
			cin >> a;
			autoescuela.aprobar(a);
		}
	}
	catch (domain_error e) {
		cout << "ERROR" << '\n';
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {	//O(N) lineal en el numero de capítulos
	string accion;
	cin >> accion;

	if (!cin)
		return false;

	autoescuela autoescuela;
	while(accion != "FIN") {
		ejecutarAccion(accion, autoescuela);
		cin >> accion;
	}
	cout << "------\n";
	return true;
}

int main() {
	while(resuelveCaso()) {
	}
		

	return 0;
}
// Grupo XYZ, Fulano y Mengano
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <vector>
#include <fstream>
#include <memory>
#include <stdexcept>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <ctype.h>
#include <queue>
#include "consultorio.h"

using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

void ejecutarAccion(string accion, consultorioMedico& consultorio) {
	string p, m;
	fecha f;
	int d;
	try {
		if (accion == "nuevoMedico") {
			cin >> m;
			consultorio.nuevoMedico(m);
		}
		else if (accion == "pideConsulta") {
			cin >> p >> m >> f;
			consultorio.pideConsulta(p, m, f);
		}
		else if (accion == "listaPacientes") {
			cin >> m >> d;

			vector<pair<fecha, string>> pacientes = consultorio.listaPacientes(m, d);
			cout << "Doctor " << m << " dia " << d << '\n';
			for (auto p : pacientes) {
				cout << p.second << " " << p.first << '\n';
			}
			cout << "---\n";
		}
		else if (accion == "siguientePaciente") {
			cin >> m;
			string nextPac = consultorio.siguientePaciente(m);
			cout << "Siguiente paciente doctor " << m << '\n';
			cout << nextPac << '\n';
			cout << "---\n";
		}
		else if (accion == "atiendeConsulta") {
			cin >> m;
			consultorio.atiendeConsulta(m);
		}
	}
	catch (domain_error e) {
		cout << e.what() << '\n';
		cout << "---\n";
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {	//O(N) lineal en el numero de capítulos
	int acciones;
	cin >> acciones;

	if (!cin)
		return false;

	string accion;
	consultorioMedico consultorio;

	for (int i = 0; i < acciones; i++) {
		cin >> accion;
		ejecutarAccion(accion, consultorio);
	}
	cout << "------\n";
	return true;
}

int main() {
	while(resuelveCaso()) {
	}
		

	return 0;
}
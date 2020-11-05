// Grupo XYZ, Fulano y Mengano
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include "Amazon.h"

using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

void ejecutarAccion(string accion, amazon& a) {
	string x;
	int n;
	try {
		if (accion == "nuevoLibro") {
			cin >> n;
			getline(cin, x);
			x.erase(x.begin());
			a.nuevoLibro(n, x);
		}
		else if (accion == "comprar") {
			getline(cin, x);
			x.erase(x.begin());
			a.comprar(x);
		}
		else if (accion == "estaLibro") {
			getline(cin, x);
			x.erase(x.begin());
			string salida = a.estaLibro(x) ? "El libro " + x + " esta en el sistema\n":
				"No existe el libro " + x + " en el sistema\n";
			cout << salida;
			cout << "---\n";
		}
		else if (accion == "numEjemplares") {
			getline(cin, x);
			x.erase(x.begin());
			try {
				int num = a.numEjemplares(x);
				cout << "Existen " << num << " ejemplares del libro " << x << '\n';
			}
			catch (invalid_argument e) {
				cout << "No existe el libro " << x << " en el sistema\n";
			}
			cout << "---\n";
		}
		else if (accion == "top10") {
			list<string> top = a.top10();
			for (auto l : top)
				cout << l << '\n';
			cout << "---\n";
		}
		else if (accion == "elimLibro") {
			getline(cin, x);
			x.erase(x.begin());
			a.elimLibro(x);
		}
	}
	catch (exception &e) {
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

	amazon a;
	string accion;
	for(int i = 0; i < acciones; i++) {
		cin >> accion;
		ejecutarAccion(accion, a);
	}
	cout << "------\n";
	return true;
}

int main() {
	while(resuelveCaso()) {
	}
		

	return 0;
}
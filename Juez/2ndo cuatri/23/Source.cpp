// Grupo XYZ, Fulano y Mengano
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include "iPud.h"

using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

void ejecutarAccion(string accion, ipud& i) {
	string s, a;
	int d;
	try {
		if (accion == "addSong") {
			cin >> s >> a >> d;
			i.addSong(s, a, d);
		}
		else if (accion == "addToPlaylist") {
			cin >> s;
			i.addToPlaylist(s);
		}
		else if (accion == "play") {
			string out = i.play();
			if (out == "")
				cout << "No hay canciones en la lista\n";
			else
				cout << "Sonando " << out << '\n';
		}
		else if (accion == "totalTime") {
			cout << "Tiempo total " << i.totalTime() << '\n';
		}
		else if (accion == "deleteSong") {
			cin >> s;
			i.deleteSong(s);
		}
		else if (accion == "recent") {
			cin >> d;
			list<string> out = i.recent(d);
			if (out.empty())
				cout << "No hay canciones recientes" << '\n';
			else {
				cout << "Las " << out.size() << " mas recientes\n";
				for (auto s : out)
					cout << "    " << s << '\n';
			}
				
		}
		else if (accion == "current") {
			i.current();
		}
	}
	catch (domain_error e) {
		cout << "ERROR " << accion << '\n';
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {	//O(N) lineal en el numero de capítulos
	string accion;
	cin >> accion;

	if (!cin)
		return false;

	ipud i;
	while(accion != "FIN") {
		ejecutarAccion(accion, i);
		cin >> accion;
	}
	cout << "----\n";
	return true;
}

int main() {
	while(resuelveCaso()) {
	}
		

	return 0;
}
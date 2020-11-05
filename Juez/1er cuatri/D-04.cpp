#include <iostream>
#include <vector>
using namespace std;

struct tJugador {
	string nombre;
	int canicas;
};

tJugador quienGana(tJugador a, tJugador b) {
	if (a.canicas >= b.canicas) {
		ganador = a;
		ganador.canicas += b.canicas / 2;
	}
	else {
		ganador = b;
		ganador.canicas += a.canicas / 2;
	}
	return ganador;
}

void resolverAux(vector<tJugadores> const &jugadores, tJugador & ganador, int ini, int fin){
	if (fin - ini == 2) { //Caso base, solo 2 jugadores
		ganador = quienGana(jugadores[ini], jugadores[ini + 1]);
	}
	else { //Caso general
		int mitad = (ini + fin) / 2;
		tJugador ganadorIzq, ganadorDer;
		resolverAux(jugadores, ganadorIzq, 0, mitad);
		resolverAux(jugadores, ganadorDer, mitad, fin);
		ganador = quienGana(ganadorIzq, ganadorDer);
	}
}

void resolver(vector<tJugadores> const &jugadores, tJugador & ganador) {
	resolverAux(jugadores, jugador, 0, jugadores.size());
}


bool resuelveCaso() {
	int participantes;
	tJugador jugador;
	vector<tJugador> jugadores;

	cin >> participantes;

	for (int i = 0; i < participantes; i++) {
		cin >> jugador.nombre >> jugador.canicas;
		jugadores.push_back(jugador);
	}

	if (!std::cin)//findelaentrada
		return false;

	tJugador ganador;
	resolver(jugadores, ganador);
	cout << ganador.nombre << " " << ganador.canicas << '\n';

	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
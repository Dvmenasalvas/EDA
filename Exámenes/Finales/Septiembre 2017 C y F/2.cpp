// Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <vector>
#include <list>
using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

void WJ(int k, int & punt, list<bool> & sec, int & mejorPunt, list<bool> & mejorSec,
	vector<int> const& i, vector<int> const & d, int izq, int der) {
	//Cogemos izquierda
	if (izq < i.size()) {
		//Marcamos
		punt += i[izq] - k;
		sec.push_back(0);
		//Tratamos
		if (k == i.size() + d.size()) {
			if (punt > mejorPunt || punt == mejorPunt && sec.size() < mejorSec.size()) {
				mejorPunt = punt;
				mejorSec = sec;
			}
		}
		else WJ(k + 1, punt, sec, mejorPunt, mejorSec, i, d, izq + 1, der);
		//Descamarcamos
		punt -= i[izq] - k;
		sec.pop_back();
	}

	//Cogemos derecha
	if (der < d.size()) {
		//Marcamos
		punt += d[der] - k;
		sec.push_back(1);
		//Tratamos
		if (k == i.size() + d.size()) {
			if (punt > mejorPunt || punt == mejorPunt && sec.size() < mejorSec.size()) {
				mejorPunt = punt;
				mejorSec = sec;
			}
		}
		else WJ(k + 1, punt, sec, mejorPunt, mejorSec, i, d, izq, der + 1);
		//Descamarcamos
		punt -= d[der] - k;
		sec.pop_back();
	}

	//Nos plantamos
	if (punt > mejorPunt || punt == mejorPunt && sec.size() < mejorSec.size()) {
		mejorPunt = punt;
		mejorSec = sec;
	}
}

void WJ(vector<int> const& i, vector<int> const & d, int & mejorPunt,
	list<bool> & mejorSec) {
	mejorPunt = 0;
	mejorSec = list<bool>();
	int punt = 0;
	list<bool> sec;
	WJ(1, punt, sec, mejorPunt, mejorSec, i, d, 0, 0);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int entrada;
	vector<int> i;
	cin >> entrada;
	while (entrada != -1) {
		i.push_back(entrada);
		cin >> entrada;
	}

	vector<int> d;
	cin >> entrada;
	while (entrada != -1) {
		d.push_back(entrada);
		cin >> entrada;
	}
	int mejorPunt;
	list<bool> mejorSec;
	WJ(i, d, mejorPunt, mejorSec);

	cout << mejorPunt << '\n';
	for (auto p : mejorSec) {
		cout << p << " ";
	}
	cout << '\n';
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
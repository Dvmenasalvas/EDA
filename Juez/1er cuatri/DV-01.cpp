#include <iostream>
#include <vector>
using namespace std;

bool seguidos(char a, char b) {
	return a + 1 == b;
}

//Utiliza recursion multiple
void resolverAux(vector<char> const & vector, int ini, int fin, char & fugado) {
	if (ini + 2 == fin) {
		if (!seguidos(vector[ini], vector[ini + 1])) fugado = vector[ini] + 1;
	}
	else {
		int mitad = (ini + fin) / 2;
		if (seguidos(vector[mitad - 1], vector[mitad])) {
			resolverAux(vector, ini, mitad, fugado);
			resolverAux(vector, mitad, fin, fugado);
		}
		else fugado = vector[mitad - 1] + 1;
	}
		
}

char resolver(vector<char> const & presos, char primero) {
	if (presos[0] == primero + 1) return primero;
	else if (presos[presos.size() - 1] + 1 == primero + presos.size()) return primero + presos.size();
	else {
		char fugado;
		resolverAux(presos, 0, presos.size(), fugado);
		return fugado;
	}
}

bool resuelveCaso() {
	char primero, ultimo, letra;
	vector<char> presos;

	cin >> primero >> ultimo;
	int tam = ultimo - primero;
	for (int i = 0; i < tam; i++) {
		cin >> letra;
		presos.push_back(letra);
	}
	cout << resolver(presos, primero) << '\n';

	return true;
}
int main() {
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; i++)
		resuelveCaso();
	return 0;
}
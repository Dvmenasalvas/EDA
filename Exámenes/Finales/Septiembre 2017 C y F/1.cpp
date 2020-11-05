// Daniel Valverde Menasalvas
// Comentario general sobre la soluci�n,
// explicando c�mo se resuelve el problema
#include <iostream>
#include <vector>
using namespace std;

// funci�n que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

bool valle(vector<int> const& v) {
	int i = 0;
	while (i < v.size() - 1 && v[i] > v[i + 1])
		i++;
	while (i < v.size() - 1 && v[i] < v[i + 1])
		i++;
	return  i == v.size() - 1;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuraci�n, y escribiendo la respuesta
bool resuelveCaso() {
	int n;
	cin >> n;
	
	if (!cin)
		return false;

	int entrada;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> entrada;
		v.push_back(entrada);
	}

	cout << valle(v) << '\n';

	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
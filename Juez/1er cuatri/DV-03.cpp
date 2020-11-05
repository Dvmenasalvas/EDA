#include <iostream>
#include <vector>
using namespace std;

void cambiar(int a, int b, vector<int> & vector, int & tiempo) {
	int aux = vector[a];
	vector[a] = vector[b];
	vector[b] = aux;
	tiempo++;
}

void mezclar(int mitad, vector<int> & vector, int ini, int fin, int & tiempo) {
	int i = ini, j = mitad;
	std::vector<int> aux;
	while (i < mitad && j < fin) {
		if (vector[i] < vector[j]) {
			aux.push_back(vector[i]);
			i++;
		}
		else {
			aux.push_back(vector[j]);
			j++;
			tiempo += mitad - i;
		}
	}
	while (i < mitad) {
		aux.push_back(vector[i]);
		i++;
	}
	while (j < fin) {
		aux.push_back(vector[j]);
		j++;
	}
	for (i = 0; i < fin - ini; i++)
		vector[ini + i] = aux[i];

}

void resolverAux(vector<int>  & vector, int ini, int fin, int & tiempo) {
	if (ini + 2 == fin) {
		if (vector[ini] > vector[ini + 1])
			cambiar(ini, ini + 1, vector, tiempo);
	}
	else if (ini + 1 != fin) {
		int mitad = (ini + fin) / 2;
		resolverAux(vector, ini, mitad, tiempo);
		resolverAux(vector, mitad, fin, tiempo);
		mezclar(mitad, vector,ini, fin, tiempo);
	}
}

int resolver(vector<int> & vector) {
	int tiempo = 0;
	resolverAux(vector, 0, vector.size(), tiempo);
	return tiempo;
}

bool resuelveCaso() {
	int tam, entrada;
	vector<int> vector;
	cin >> tam;
	for (int i = 0; i < tam; i++) {
		cin >> entrada;
		vector.push_back(entrada);
	}
	if (!std::cin) // fin de la entrada
		return false;
	cout << resolver(vector) << '\n';
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
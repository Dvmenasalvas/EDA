#include <iostream>
#include <vector>
using namespace std;

//Utiliza recursion multiple

void resolver(long long raiz, int digitos, int maxDigitos) {
	cout << raiz << '\n';
	if (digitos < maxDigitos) {
		long long posible = raiz * 10;
		int resto = posible % (digitos + 1);
		int actual = 0;
		if (resto == 0) resolver(posible, digitos + 1, maxDigitos);
		else {
			int distancia = (digitos + 1) - resto;
			if (distancia < 10) {
				actual = distancia;
				resolver(posible + actual, digitos + 1, maxDigitos);
			}
		}
		while (digitos + 1 + actual < 10) {
			actual += digitos + 1;
			resolver(posible + actual, digitos + 1, maxDigitos);
		}


	}
}

void escribirPolidivisibles(long long raiz, int maxDigitos) {
	int digitos = 1;
	long long resto = raiz;
	while (resto >= 10) {
		resto /= 10;
		digitos++;
	}
	resolver(raiz, digitos, maxDigitos);
	cout << "---" << '\n';
}

bool resuelveCaso() {
	long long raiz;
	int maxDigitos;

	cin >> raiz >> maxDigitos;

	if (!std::cin)//findelaentrada
		return false;

	escribirPolidivisibles(raiz, maxDigitos);

	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
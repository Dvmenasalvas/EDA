// Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <vector>

// función que resuelve el problema
// La funcion pertenece a O(N)
//{A ~ 2 <= N <= 100000 ^ 1 <= alturas[i] <= 10^6 con 0 <= i < alturas.size()}
bool resolver(std::vector<int> const & v) {  //
	bool sol = true, creciente = true;
	int i = 0;
	if (v[0] >= v[1]) creciente = false;
	if (creciente) {
		while (sol && i < v.size() - 1) {		//Funcion de cota: C = v.size() - i 
			if (v[i] >= v[i + 1]) sol = false;	//{I ~ 0 <= i < v.size() ^ ∀k,j  z < j < i  v[k] < v[j]}
			i++;
		}
	}
	else {
		while (sol && i < v.size() - 1) {		//Funcion de cota: C = v.size() - i
			if (v[i] <= v[i + 1]) sol = false;	//{I ~ 0 <= i < v.size() ^ ∀k,j  k < j < i  v[k] > v[j]}
			i++;
		}
	}
	return sol;
}//{B ~ sol =  ∀i,j  i < j  v[i] < v[j] || ∀i,j  i < j  v[i] > v[j] }

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int N;
	std::cin >> N;
	if (N == 0)
		return false;

	std::vector<int> alturas;
	for (int i = 0; i < N; i++) { 
		int entrada;
		std::cin >> entrada; 
		alturas.push_back(entrada);
	}
	bool sol = resolver(alturas);
	if (sol) std::cout << "DALTON" << '\n';
	else std::cout << "DESCONOCIDOS" << '\n';
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
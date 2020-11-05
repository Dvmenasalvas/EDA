#include <iostream>
#include <vector>
using namespace std;

//El coste de la solución es lineal, utiliza recursion multiple
bool gResolver(vector<int> const &fila, int inicio, int fin, int& suma) {
	bool sol = false;
	if (fin - inicio == 1) sol = true;
	else if (fin - inicio == 2) {
		suma = fila[inicio] + fila[fin - 1];
		sol = fila[inicio] < fila[fin - 1];
	}
	else {
		int suma1, suma2;
		if(gResolver(fila, inicio, (inicio + fin) / 2, suma1))
			if(gResolver(fila, (inicio + fin) / 2, fin, suma2))
				if (suma1 < suma2) {
					suma = suma1 + suma2;
					sol = true;
				}
	}
	return sol;
}

 bool resolver(vector<int> const &fila) {
	 int suma;
	 return gResolver(fila, 0, fila.size(), suma);
}

 bool resuelveCaso() {
	 int n = 0, m = 0;
	 cin >> n >> m;
	 vector<vector<int>> matriz;
	 int entrada;
	 for (int i = 0; i < n; i++) {
		 vector<int> fila;
		 for (int j = 0; j < m; j++) {
			 cin >> entrada;
			 fila.push_back(entrada);
		 }
		 matriz.push_back(fila);
	 }
	if (!std::cin)//findelaentrada
		return false;
	bool degradado = true;
	int i = 0;
	while (degradado && i < n) {
		degradado = resolver(matriz[i]);
		i++;
	}
	if (degradado) cout << "SI" << '\n';
	else cout << "NO" << '\n';
	 
	return true;
 }
int main() {
	 while (resuelveCaso());
	 return 0;
 }

// Daniel Valverde Menasalvas
#include <iostream>
#include <vector>
using namespace std;


void mercadosVA(int k, int & coste, int & mejorCoste, vector<vector<int>> const &precios, vector<int> const &mejoresPrecios, int & cotaInferior, vector<int> &mercadosUsados) {
	//Probamos coger el producto k en cada uno de los mercados
	cotaInferior -= mejoresPrecios[k];		//Adaptamos la cota, quitando el producto k de la estimacion
	for (int i = 0; i < precios.size(); i++) {
		if (mercadosUsados[i] < 3) {		//Comprobamos q aun no hemos comprado tres productos en este mercado
			//Marcamos
			mercadosUsados[i]++;
			coste += precios[i][k];
			//Estimamos
			if (coste + cotaInferior < mejorCoste) {	//Si es candidato a mejorar el precio, lo tratamos
				if (k == precios[0].size() - 1) mejorCoste = coste;			//Si no quedan productos, esta es la nueva mejor solucion
				else mercadosVA(k + 1, coste, mejorCoste, precios, mejoresPrecios, cotaInferior, mercadosUsados);	//Si quedan productos, avanzamos en la solucion
			}
			//Desmarcamos
			mercadosUsados[i]--;
			coste -= precios[i][k];
		}
	}
	cotaInferior += mejoresPrecios[k];		//Dejamos la cota lista para el producto k - 1
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int M, P;
	cin >> M >> P;
	int precio;
	vector<vector<int>> precios;
	for (int i = 0; i < M; i++) {
		vector<int> mercado;
		for (int j = 0; j < P; j++) {
			cin >> precio;
			mercado.push_back(precio);
		}
		precios.push_back(mercado);
	}
	int coste = 0, mejorCoste = 0;
	int aux = 0, i = 0;
	for (int j = 0; j < P; j++) { //Conseguimos un mejorCoste viable
		if (aux == 3) {
			i++;
			aux = 0;
		}
		mejorCoste += precios[i][j];
		aux++;
	}
	vector<int> mejoresPrecios;
	for (int j = 0; j < P; j++) { //Vector de mínimos de precios de cada producto(columnas) que usaremos para la estimacion
		int mejorPrecio = precios[0][j];
		for (int i = 1; i < M; i++) {
			if (precios[i][j] < mejorPrecio) mejorPrecio = precios[i][j];
		}
		mejoresPrecios.push_back(mejorPrecio);
	}
	int cotaInferior = 0;
	for (int i = 0; i < P; i++) cotaInferior += mejoresPrecios[i]; //La cotaInferior es la suma de los mejores precios posibles
	vector<int> mercadosUsados; //Vector usado para marcar cuantos productos hemos comprado en cada supermercado
	for (int i = 0; i < M; i++) 
		mercadosUsados.push_back(0);

	mercadosVA(0, coste, mejorCoste, precios, mejoresPrecios, cotaInferior, mercadosUsados);
	cout << mejorCoste << '\n';
}
int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}
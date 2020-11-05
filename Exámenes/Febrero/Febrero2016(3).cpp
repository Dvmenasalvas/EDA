// Grupo XYZ, Fulano y Mengano
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <vector>
using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

bool mover(int &i, int &j, int dir, int N) {
	if (dir == 0 && i < N - 1) i++;			//Abajo
	else if (dir == 1 && j > 0) j--;	//Izquierda	
	else if (dir == 2 && i > 0) i--;	//Arriba
	else if (dir == 3 && j < N - 1) j++;	//Derecha
	else return false;
}

void resolver(int k, int actual_i, int actual_j, vector<vector<int>> const &matriz, int & mejorLong, vector<vector<bool>> &libres, int hMax, int fin_i, int fin_j) {
	//Probamos las cuatro direcciones
	if (k + 1 < mejorLong) {
		for (int dir = 0; dir < 4; dir++) {
			int nueva_i = actual_i;
			int nueva_j = actual_j;
			if (mover(nueva_i, nueva_j, dir, matriz.size())) {					//No es borde
				if (libres[nueva_i][nueva_j]) {									//No hemos pasado por esa casilla
					if (abs(matriz[actual_i][actual_j] - matriz[nueva_i][nueva_j]) <= hMax) {	//El salto no es demasiado grande
						//Marcamos
						libres[nueva_i][nueva_j] = false;
						//Tratamos
						if (nueva_i == fin_i && nueva_j == fin_j) mejorLong = k + 1;
						else resolver(k + 1, nueva_i, nueva_j, matriz, mejorLong, libres, hMax, fin_i, fin_j);
						//Desmarcamos
						libres[nueva_i][nueva_j] = true;
					}
				}
			}
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	vector<vector<int>> matriz;
	int N, entrada, ini_i, ini_j, fin_i, fin_j, hMax;
	cin >> N >> ini_i >> ini_j >> fin_i >> fin_j >> hMax;
	for (int i = 0; i < N; i++) {
		vector<int> fila;
		for (int j = 0; j < N; j++) {
			cin >> entrada;
			fila.push_back(entrada);
		}
		matriz.push_back(fila);
	}

	int mejorLong = N * N;
	vector<vector<bool>> libres;
	vector<bool> fila(N, true);
	for (int i = 0; i < N; i++)
		libres.push_back(fila);
	libres[ini_i][ini_j] = false;
	/*
	vector<vector<int>> solucion;
	vector<int> inicio = { ini_i, ini_j };
	solucion.push_back(inicio);
	*/
	resolver(1, ini_i, ini_j, matriz, mejorLong, libres, hMax, fin_i, fin_j);
	cout << mejorLong << '\n';
}
int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}
	

/*
3 0 1 0 0 2
2 7 4
3 6 3
4 5 1
*/
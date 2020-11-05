// Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <vector>
using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

double ratio(vector<int> cancion) {
	return double(cancion[1]) / cancion[0];
}

double estimacion(int k, int valor, int peso1, int peso2, vector<vector<int>> const &canciones, int durCara) {
	double estimacion = valor;
	int i = k, hueco1 = durCara - peso1, hueco2 = durCara - peso2;
	while (i < canciones.size() && canciones[i][0] <= hueco1) { //Llenamos la primera cinta
		hueco1 -= canciones[i][0];
		estimacion += canciones[i][1];
		i++;
	}
	if (i < canciones.size()) {			//Si queda algun elemento lo partimos para que quepa
		estimacion += (double(hueco1) / canciones[i][0]) * canciones[i][1];
		int resto = canciones[i][0] - hueco1;	//Aprovechamos lo que queda del objeto en la segunda cinta para hacer una estimacion mas precisa
		if (resto < hueco2) {
			hueco2 -= resto;
			estimacion += (double(resto) / canciones[i][0]) * canciones[i][1];
		}
		else estimacion += (double(hueco2) / canciones[i][0]) * canciones[i][1];
		i++;
	}
	while (i < canciones.size() && canciones[i][0] <= hueco2) { //Llenamos la segunda cinta
		hueco2 -= canciones[i][0];
		estimacion += canciones[i][1];
		i++;
	}
	if (i < canciones.size())		//Si queda algun elemento lo partimos para que quepa
		estimacion += (double(hueco2) / canciones[i][0]) * canciones[i][1];
	return estimacion;
}

void cintaVA(int k, int &valor, int &peso1, int &peso2, int &mejorValor, vector<vector<int>> const & canciones, int durCara) {
	//La cogemos en la primera cara
	peso1 += canciones[k][0];
	if (peso1 <= durCara) {
		valor += canciones[k][1];
		if (k == canciones.size() - 1) {
			if (valor > mejorValor) 
				mejorValor = valor;
		}
		else cintaVA(k + 1, valor, peso1, peso2, mejorValor, canciones, durCara);
		valor -= canciones[k][1];
	}
	peso1 -= canciones[k][0];
	//La cogemos en la segunda cara
	peso2 += canciones[k][0];
	if (peso2 <= durCara) {
		valor += canciones[k][1];
		if (k == canciones.size() - 1) {
			if (valor > mejorValor)
				mejorValor = valor;
		}
		else cintaVA(k + 1, valor, peso1, peso2, mejorValor, canciones, durCara);
		valor -= canciones[k][1];
	}
	peso2 -= canciones[k][0];
	//No la cogemos
	if (estimacion(k + 1, valor, peso1, peso2, canciones, durCara) > mejorValor) {
		if (k == canciones.size() - 1) mejorValor = valor;
		else cintaVA(k + 1, valor, peso1, peso2, mejorValor, canciones, durCara);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int N;
	cin >> N;
	if (N == 0) return false;

	int durCara;
	cin >> durCara;
	
	int duracion, puntuacion;
	vector<vector<int>> canciones(N);
	for (int i = 0; i < N; i++) {	//[0]Duracion [1]Puntuacion
		vector<int> cancion;		//Leemos las canciones y las ordenamos por ratio
		cin >> duracion >> puntuacion;
		cancion.push_back(duracion);
		cancion.push_back(puntuacion);
		int j = i;
		double rCancion = ratio(cancion);
		while (j > 0 && ratio(canciones[j - 1]) < rCancion) //Buscamos su posicion
			j--;

		for (int z = i; z > j; z--)	//Hacemos hueco y colocamos
			canciones[z] = canciones[z - 1];
		canciones[j] = cancion;
	}
	int valor = 0, mejorValor = -1, peso1 = 0, peso2 = 0;
	cintaVA(0, valor, peso1, peso2, mejorValor, canciones, durCara);
	cout << mejorValor << '\n';
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
//Daniel Valverde Menasalvas
//Comentariogeneralsobrelasolución,
//explicandocómoseresuelveelproblema
#include<iostream>
#include<vector>
using namespace std;
//funciónqueresuelveelproblema
//comentariosobreelcoste,O(f(N)),dondeNes...

/* 
{N > 0}
fun tamSegmentoMaximo(V[0..N) de ent) de longitud: ent
{longitud = (max b - a + 1: 0 <= a < b: iguales(V, a, b))}
iguales(V, a, b) = {∀i,j: b >= i,j >= a: V[i] == V[j]}

I = {1 <= i <= N ^ longitud = (max b - a + 1: 0 <= a <= b < i: iguales(V, a, b))}
C = N - i
*/

int tamSegmentoMaximo(vector<int> km) {
	int longitud = 1, act = 1;
	for (int i = 1; i < km.size(); i++) {
		if (km[i] == km[i - 1])act++;
		else act = 1;
		if (act > longitud) longitud = act;
	}
	return longitud;
}

bool resuelveCaso() {
	vector<int> km;
	int entrada;
	cin >> entrada;
	while (entrada != -1) {
		km.push_back(entrada);
		cin >> entrada;
	}
		if (km.size() == 0)
			return false;
	int sol = tamSegmentoMaximo(km);
	sol--;
	if (sol == 0) cout << "HOY NO COMEN" << '\n';
	else cout << sol << '\n';
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
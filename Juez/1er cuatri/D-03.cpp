//Daniel Valverde Menasalvas
//Comentariogeneralsobrelasolución,
//explicandocómoseresuelveelproblema
#include<iostream>
#include<vector>
using namespace std;

/*
{N > 0}
func criogenizacion(V[0..N)) dev <mayor: ent, fMayor: ent, menor: ent, fMenor: ent>
{mayor = (max i : 0 <= i < N: V[i]) ^ fMayor = (#i: 0 <= i < N: V[i] == mayor) ^ menor = (min i : 0 <= i < N: V[i]) ^ fMenor = (#i: 0 <= i < N: V[i] == menor)}

I = {1 <= i <= N ^ mayor = (max t : 0 <= t < i: V[t]) ^ fMayor = (#t: 0 <= t < i: V[t] == mayor) ^ menor = (min t : 0 <= t < i: V[t]) ^ fMenor = (#t: 0 <= t < i: V[t] == menor)}
C = N - i
*/

void criogenizacion(vector<long long int> temperaturas, long long int &mayor, long int &fMayor, long long int menor, long int &fMenor) {
	for (int i = 1; i < temperaturas.size(); i++) {
		if (temperaturas[i] > mayor) {
			mayor = temperaturas[i];
			fMayor = 1;
		}
		else if (temperaturas[i] < menor) {
			menor = temperaturas[i];
			fMenor = 1;
		}
		else {
			if (temperaturas[i] == mayor) fMayor++;
			if (temperaturas[i] == menor) fMenor++;
		}
	}
}
//Resuelveuncasodeprueba,leyendodelaentradala
//configuración,yescribiendolarespuesta
void resuelveCaso() {
	vector<long long int> temperaturas;
	long long int entrada, mayor, menor;
	long int fMayor, fMenor;
	cin >> entrada;
	while (entrada != 0) {
		temperaturas.push_back(entrada);
		cin >> entrada;
	}
	mayor = temperaturas[0];
	menor = mayor;
	fMayor = 1;
	fMenor = 1;
	criogenizacion(temperaturas, mayor, fMayor, menor, fMenor);
	cout << menor << " " << fMenor  << " " << mayor << " " << fMayor << '\n';
} 
int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}
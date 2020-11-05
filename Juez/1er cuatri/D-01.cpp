//Daniel Valverde Menasalvas
//Comentariogeneralsobrelasolución,
//explicandocómoseresuelveelproblema
#include<iostream>
#include<vector>
using namespace std;
//funciónqueresuelveelproblema
//comentariosobreelcoste,O(f(N)),dondeNes...

//{0 <= N}
//fun buscarPicos(V[0..N) de ent) dev picos: ent
//{picos =(#t: 1 <= t < N: V[t-1] < V[t] > V[t+1])}

//C = N - i
//I = { 1 <= i <= N ^ picos =(#t: 1 <= t <= i: V[t-1] < V[t] > V[t+1])}

int buscarPicos(vector<int> const &temperaturas) {
	int picos = 0;
	for (int i = 1; i < temperaturas.size() - 1; i++)
		if (temperaturas[i] > temperaturas[i - 1] && temperaturas[i] > temperaturas[i + 1])
			picos++;
	return picos;
}

//{0 <= N}
//fun buscarValles(V[0..N) de ent) dev valles: ent
//{valles =(#t: 1 <= t < N: V[t-1] > V[t] < V[t+1])}

//C = N - i
//I = { 1 <= i <= N ^ valles =(#t: 1 <= t <= i: V[t-1] < V[t] > V[t+1])}

int buscarValles(vector<int> const &temperaturas) {
	int valles = 0;
	for (int i = 1; i < temperaturas.size() - 1; i++)
		if (temperaturas[i] < temperaturas[i - 1] && temperaturas[i] < temperaturas[i + 1])
			valles++;
	return valles;
}

void resolver(int &picos, int &valles, vector<int> const &temperaturas) {
	picos = buscarPicos(temperaturas);
	valles = buscarValles(temperaturas);

}


//Resuelveuncasodeprueba,leyendodelaentradala
//configuración,yescribiendolarespuesta
void resuelveCaso() {
	int tam;
	std::vector<int> temperaturas;
	int picos;
	int valles;
	std::cin >> tam;
	for (int j = 0; j < tam; j++) {
		int temperatura;
		cin >> temperatura;
		temperaturas.push_back(temperatura);
	}
	resolver(picos, valles, temperaturas);
	cout << picos << " " << valles << '\n';
}
int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}
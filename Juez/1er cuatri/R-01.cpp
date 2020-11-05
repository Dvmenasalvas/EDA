#include <iostream>
#include <vector>
using namespace std;

//El coste de la funcion es lineal y la recurrencia es multiple
bool gResolver(vector<int> const &vector, int inicio, int fin, int &min, int &max) {
	if (fin - inicio == 1) return true;
	else if (fin - inicio == 2) {
		if (vector[inicio] <= vector[fin - 1]) {
			min = vector[inicio];
			max = vector[fin - 1];
			return true;
		}
		else
			return false;
	}
	else {
		int min1, min2, max1, max2;
		if (gResolver(vector, inicio, (inicio + fin) / 2, min1, max1))
			if (gResolver(vector, (inicio + fin) / 2, fin, min2, max2)) {
				if (min1 <= min2 && max1 <= max2) {
					min = min1;
					max = max2;
					return true;
				}
			}
		return false;
	}
	
}

 bool resolver(vector<int> const &vector) {
	 int min, max;
	 return gResolver(vector, 0, vector.size(), min, max);
}

bool resolverCaso() {
	int entrada;
	cin >> entrada;
	if (entrada == 0) return false;
	else {
		vector<int> vector;
		while (entrada != 0) {
			vector.push_back(entrada);
			cin >> entrada;
		}
		if (resolver(vector)) cout << "SI" << '\n';
		else cout << "NO" << '\n';
	}
	return true;
}

int main() {
	while (resolverCaso());

	return 0;
}
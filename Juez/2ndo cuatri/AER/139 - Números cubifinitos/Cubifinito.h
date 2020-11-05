#include <iostream>
#include <vector>

class cubifinito {
public:
	void esCubifinito(std::ostream & o = std::cout) {
		std::vector<int> numeros;
		numeros.push_back(num);
		std::cout << num;
		bool error = false;
		int act = num;
		while (!error && act != 1) {
			act = siguiente(act);
			std::cout << " - " << act;
			numeros.push_back(act);
			for (int i = 0; i < numeros.size() - 1; i++)
				if (act == numeros[i]) error = true;
		}
		std::cout << " -> ";
		if (error) {
			std::cout << "no cubifinito.\n";
		}
		else {
			std::cout << "cubifinito.\n";
		}
	}

	void read(std::istream & i = std::cin) {
		i >> num;
	}

	bool operator == (int n) {
		return num == n;
	}

private:
	int num;

	int siguiente(int act) {
		int aux = act;
		int suma = 0;
		while (aux >= 10) {
			suma += pow(aux % 10, 3);
			aux /= 10;
		}
		suma += pow(aux, 3);
		return suma;
	}
};

inline std::istream & operator >> (std::istream & i, cubifinito & c) {
	c.read(i);
	return i;
}
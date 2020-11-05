#include <string>
#include <unordered_map>
#include <unordered_set>

using dni = std::string;

class CarnetPorPuntos {
	std::unordered_map<dni, int> conductores;
	std::unordered_map<int, int> puntos;

	void nuevo(dni d) {
		if (conductores.count(d))
			throw std::domain_error("Conductor duplicado");

		conductores[d] = 15;
		puntos[15]++;
	}

	void quitar(dni d, int p) {
		auto it = conductores.find(d);
		if (it == conductores.end())
			throw std::domain_error("Conductor inexistente");

		puntos[it->second]--;
		it->second = it->second < p ? 0 : it->second - p;
		puntos[it->second]++;
	}

	int consultar(dni d) {
		auto it = conductores.find(d);
		if (it == conductores.end())
			throw std::domain_error("Conductor inexistente");

		return it->second;
	}

	int cuantos_con_puntos(int p) {
		if (p < 0 || p > 15)
			throw std::domain_error("Puntos no validos");

		return puntos[p];
	}
};
#include <unordered_map>
#include <set>
#include <stdexcept>
#include <vector>

using alumno = std::string;
using profesor = std::string;

class autoescuela {
private:
	std::unordered_map<alumno, std::pair<profesor, int>> alumnos;
	std::unordered_map<profesor, std::set<alumno>> profesores;
public:
	autoescuela() {}

	//O(log(N+M)) en el numero de alumnos del profesor anterior y del actual
	void alta(alumno a, profesor p) {	
		if (alumnos.count(a)) 
			profesores[alumnos[a].first].erase(a);
		
		profesores[p].insert(a);
		alumnos[a].first = p;
	}

	//O(logN) numero de alumnos de p
	bool esAlumno(alumno a, profesor p) {
		return profesores[p].count(a);
	}
	
	//Constante
	int puntuacion(alumno a) {
		if (!alumnos.count(a))
			throw std::domain_error("El alumno A no esta matriculado");

		return alumnos[a].second;
	}

	//Constante
	void actualizar(alumno a, int n) {
		if (!alumnos.count(a))
			throw std::domain_error("El alumno A no esta matriculado");

		alumnos[a].second += n;
	}

	//O(N) en el numero de alumnos del profesor
	std::vector<alumno> examen(profesor p, int n) {
		std::vector<alumno> salida;
		for (auto a : profesores[p]) {
			if (alumnos[a].second >= n)
				salida.push_back(a);
		}

		return salida;
	}

	//O(logN) en el numero de alumnos del profesor de 
	void aprobar(alumno a) {
		if (!alumnos.count(a))
			throw std::domain_error("El alumno A no esta matriculado");

		profesores[alumnos[a].first].erase(a);
		alumnos.erase(a);
	}
};
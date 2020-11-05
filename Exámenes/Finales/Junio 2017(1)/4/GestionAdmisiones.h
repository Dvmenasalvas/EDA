#ifndef autoestuela_h
#define autoescuela_h
#include <string>
#include <unordered_map>
#include <list>

using codigo = std::string;

class gestionAdmisiones {
private:
	struct paciente {
		std::string nombre;
		int edad;
		std::string sintomas;
		std::list<codigo>::iterator espera;
	};
	std::unordered_map<codigo, paciente> pacientes;
	std::list<codigo> espera;
	
public:
	gestionAdmisiones() {}

	gestionAdmisiones crea() {
		return gestionAdmisiones();
	}

	void an_paciente(codigo c, std::string n, int e, std::string s) {
		if (pacientes.count(c))
			throw std::domain_error("Paciente duplicado");

		paciente nuevo;
		nuevo.nombre = n;
		nuevo.edad = e;
		nuevo.sintomas = s;
		nuevo.espera = espera.insert(espera.end(), c);
		pacientes[c] = nuevo;
	}

	void info_paciente(codigo c, std::string &n, int &e, std::string &s) {
		auto it = pacientes.find(c);
		if (it == pacientes.end())
			throw std::domain_error("Paciente inexistente");

		n = it->second.nombre;
		e = it->second.edad;
		s = it->second.sintomas;
	}

	void siguiente(codigo c) {
		c = espera.front();
	}

	bool hay_pacientes() {
		return espera.size() > 0;
	}

	void elimina(codigo c) {
		auto it = pacientes.find(c);
		if (it != pacientes.end()) {
			espera.erase(it->second.espera);
			pacientes.erase(it);
		}
	}

};

#endif // !autoestuela_h

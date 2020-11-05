#include <string>
#include <unordered_map>
#include <map>
#include <stdexcept>
#include <vector>
#include <iostream> 
#include <iomanip>

class fecha {
private:
	int dia, hora, minuto;

public:
	fecha(int d = 0, int h = 0, int m = 0) : dia(d), hora(h), minuto(m) {}

	int getDia() const {
		return dia;
	}

	int getHora() const {
		return hora;
	}

	int getMinuto() const {
		return minuto;
	}

	bool operator < (fecha const & b) const {
		if (dia == b.getDia()) {
			if (hora == b.getHora()) {
				return minuto < b.getMinuto();
			}
			else return hora < b.getHora();
		}
		else return dia < b.getDia();
	}

	void read(std::istream& in = std::cin) {
		in >> dia >> hora >> minuto;
	}

	void write(std::ostream& out = std::cout) const{
		out << std::setfill('0') << std::setw(2) << hora << ':' << std::setw(2) << minuto;
	}
};

inline std::istream& operator>>(std::istream& in, fecha &f) {
	f.read(in);
	return in;
}

inline std::ostream & operator<<(std::ostream& out, fecha &f) {
	f.write(out);
	return out;
}

using medico = std::string;
using paciente = std::string;

class consultorioMedico :
	private std::unordered_map < medico, std::map < fecha, paciente>> {
public:
	void nuevoMedico(medico const &m) {
		insert({m,{}});
	}

	void pideConsulta(paciente const &p, medico const &m, fecha const &f) {
		auto it = find(m);
		if (it == end())
			throw std::domain_error("Medico no existente");
		else if(it->second.count(f))
			throw std::domain_error("Fecha ocupada");
		else it->second.insert({ f,p });
	}

	paciente siguientePaciente(medico const &m) const{
		auto it = find(m);
		if (it == end())
			throw std::domain_error("Medico no existente");
		else if(it->second.empty())
			throw std::domain_error("No hay pacientes");
		else return it->second.begin()->second;
	}

	void atiendeConsulta(medico const &m) {
		auto it = find(m);
		if (it == end())
			throw std::domain_error("Medico no existente");
		else if (it->second.empty())
			throw std::domain_error("No hay pacientes");
		else it->second.erase(it->second.begin());
	}

	std::vector<std::pair<fecha,paciente>> listaPacientes(medico const &m, int const &d) const {
		auto it = find(m);
		if (it == end())
			throw std::domain_error("Medico no existente");

		std::vector<std::pair<fecha,paciente>> pacientes;
		//Llegamos al primero de ese día
		auto it2 = it->second.lower_bound({ d,0,0 });
		//Añadimos todos pacientes del dia
		while (it2 != it->second.end() && it2->first.getDia() == d) {
			pacientes.push_back({ it2->first, it2->second });
			it2++;
		}
		
		return pacientes;
	}
};
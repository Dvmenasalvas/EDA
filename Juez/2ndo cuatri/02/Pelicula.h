#ifndef pelicula_h
#define pelicula_h

#include "Hora.h"
#include <string>
#include <iostream>

class pelicula {
public:
	hora getEnd() const{
		return end;
	}

	std::string getTitulo() const {
		return titulo;
	}

	pelicula(hora inicio = hora(), hora duracion = hora(), std::string tit = "") {
		titulo = tit;
		end = inicio + duracion;
	}

	bool operator<(pelicula const& p) const {
		return end < p.getEnd() || end == p.getEnd() && titulo < p.getTitulo();
	}

	void write(std::ostream & out = std::cout)const {
		out << end << " " << titulo << '\n';
	}

	pelicula read(std::istream & in = std::cin) {
		hora inicio, duracion;
		in >> inicio >> duracion;
		std::string titulo;
		getline(in, titulo);
		return pelicula(inicio, duracion, titulo);
	}
private:
	hora end;
	std::string titulo;
};

inline std::ostream & operator<<(std::ostream & out, pelicula const& p) {
	p.write(out);
	return out;
}

inline std::istream & operator>>(std::istream & in, pelicula & p) {
	p = p.read(in);
	return in;
}

#endif

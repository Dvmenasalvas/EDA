#include <string>
#include <iostream>

class persona {
private:
	std::string nombre;
	int edad;
public:

	int getEdad() {
		return edad;
	}

	std::istream & read(std::istream & in = std::cin) {
		in >> edad;
		getline(in, nombre);
		nombre = nombre.substr(1, nombre.size() - 1);
		return in;
	}

	std::ostream & write(std::ostream & o = std::cout) const{
		o << nombre;
		return o;
	}
};

inline std::istream & operator >> (std::istream & in, persona & per) {
	per.read(in);
	return in;
}
	
inline std::ostream & operator << (std::ostream & o, persona const & per) {
	per.write(o);
	return o;
}
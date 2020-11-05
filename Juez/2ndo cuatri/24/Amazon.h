#include <unordered_map>
#include <map>
#include <stdexcept>
#include <list>
#include <functional>

using libro = std::string;

class amazon {
private:
	struct contenido {
		int cantidad;
		int vendidos;
		std::list<libro>::iterator ventas;
	};
	std::unordered_map<libro, contenido> libros;
	std::map<int, std::list<libro>, std::greater<int>> ventas;
public:
	//Constante
	void nuevoLibro(int n, libro x) {
		auto it = libros.find(x);
		if (it == libros.end()) {
			contenido cont;
			cont.cantidad = n;
			cont.vendidos = 0;
			//cont.ventas = addToTopList(0, x);
			libros.insert({ x,cont });
		}
		else
			it->second.cantidad += n;
	}

	//Constante
	void comprar(libro x) {
		auto it = libros.find(x);
		if(it == libros.end())
			throw std::invalid_argument("Libro no existente");
		if (it->second.cantidad == 0)
			throw std::out_of_range("No hay ejemplares");
		
		--it->second.cantidad;
		if(it->second.vendidos != 0)
			ventas[it->second.vendidos].erase(it->second.ventas);
		
		it->second.ventas = addToTopList(++it->second.vendidos, x);
	}
	
	//Constante
	bool estaLibro(libro x) {
		return libros.count(x);
	}

	//Constante
	void elimLibro(libro x) {
		auto it = libros.find(x);
		if (it != libros.end()) {
			if(it->second.vendidos != 0)
				ventas[it->second.vendidos].erase(it->second.ventas);
			libros.erase(it);
		}
	}

	//Constante
	int numEjemplares(libro x) {
		auto it = libros.find(x);
		if (it == libros.end())
			throw std::invalid_argument("Libro no existente");
		return it->second.cantidad;
	}

	//Constante 
	std::list<libro> top10() {
		std::list<libro> salida;
		auto it = ventas.begin();
		int i = 0;
		while (i < 10 && it != ventas.end()) {
			auto it2 = it->second.begin();
			while (i < 10 && it2 != it->second.end()) {
				salida.push_back(*it2);
				i++;
				it2++;
			}
			it++;
		}
		return salida;
	}
private:
	std::list<libro>::iterator addToTopList(int vendidos, libro x) {
		auto it = ventas.find(vendidos);
		if (it != ventas.end()) {
			it->second.push_front(x);
			return it->second.begin();
		}
		else {
			auto it2 = ventas.insert({ vendidos,{ x } });
			return it2.first->second.begin();
		}
	}
};
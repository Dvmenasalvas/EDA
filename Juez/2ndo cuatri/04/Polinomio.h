#ifndef polinomio_h
#define polinomio_h

#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

struct monomio {
	int c, e;

	bool operator < (monomio const & m1) {
		return e < m1.e;
	}
	
	void read(std::istream & in = std::cin) {
		in >> c >> e;
	}

	bool nulo() {
		return c == 0 && e == 0;
	}
};

inline std::istream & operator >> (std::istream & in, monomio & m) {
	m.read();
	return in;
}
class polinomio {
public:
	void aniadirM(monomio m) {
		if (p.size() == 0) p.push_back(m);
		else {
			auto pos = std::lower_bound(p.begin(), p.end(), m);
			if (pos == p.end()) p.push_back(m);
			else if (pos->e == m.e) pos->c += m.c;
			else p.insert(pos, m);
		}
	}

	int evaluar(int v) {
		int x = pow(v, p[0].e);
		int resultado = x * p[0].c;
		for (int i = 1; i < p.size(); i++) {
			for (int j = p[i - 1].e; j < p[i].e; j++)
				x *= v;
			resultado += x * p[i].c;
		}
		return resultado;
	}

private:
	std::vector<monomio> p;
};
#endif // !polinomio_h

#ifndef complejo_h
#define complejo_h

#include <math.h>
#include <fstream>
#include <iostream>

template<class T>
class complejo {
public:
	T getReal() const {return real;}
	T getImag() const {return imag;}

	complejo(T r = 0, T i = 0): real(r), imag(i){}

	complejo operator +(complejo const & c) const {
		return complejo(real + c.getReal(), imag + c.getImag());
	}

	complejo operator *(complejo const & c) const {
		return complejo(c.getReal() * real - c.getImag() * imag,c.getImag() * real + imag * c.getReal());
	}

	T mod() const { return sqrt(real * real + imag * imag); }

	void read(std::istream & in = std::cin) {
		in >> real >> imag;
	}


private:
	T real, imag;
};

template <class T>
inline std::istream & operator>>(std::istream & in, complejo<T> &c) {
	c.read(in);
	return in;
}


#endif // !complejo_h


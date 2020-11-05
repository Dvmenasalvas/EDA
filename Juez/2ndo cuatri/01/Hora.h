#include <iostream>
#include <iomanip>
#include <stdexcept>

class hora {
public:
	int getHoras() const { return HH; }
	int getMinutos() const { return MM; }
	int getSegundos() const { return SS; }

	bool check(int h, int m, int s) const {
		return 0 <= h && h <= 23 && 0 <= m && m <= 59 && 0 <= s && s <= 59;
	}

	hora(int h = 0, int m = 0, int s = 0): HH(h), MM(m), SS(s){
		if (!check(h, m, s))
			throw std::domain_error("Hay un error en la hora.");
	}

	bool operator < (hora const & otra) const {
		return HH < otra.getHoras() || HH == otra.getHoras() && MM < otra.getMinutos() || HH == otra.getHoras() && MM == otra.getMinutos() && SS < otra.getSegundos();
	}

	void write(std::ostream & output = std::cout) const {
		output << std::setfill('0');
		output << std::setw(2) << HH << ":" << std::setw(2) << MM<< ":" << std::setw(2) << SS;
	}

	void read(std::istream & input = std::cin) {
		int h, m, s; char c;
		input >> h >> c >> m >> c >> s;
		if (check(h, m, s)) {
			HH = h;
			MM = m;
			SS = s;
		}
		else 
			throw std::domain_error("Hay un error en la hora leida.");
	}

private:
	int HH, MM, SS;
};

inline std::ostream & operator<<(std::ostream & out, hora const& h) {
	h.write(out);
	return out;
}

inline std::istream & operator>>(std::istream & in, hora & h) {
	h.read(in);
	return in;
}
#include <unordered_map>
#include <stdexcept>
#include <list>
using namespace std;

using cancion = std::string;
using artista = std::string;

class ipud {
private:
	struct contenido {
		artista art;
		int duracion;
		list<cancion>::iterator playlist;
		list<cancion>::iterator played;
	};
	unordered_map<cancion, contenido> canciones;
	list<cancion> playlist;
	list<cancion> played;
	int duracion = 0;

public:
	//O(K) constante (lo que tarde en hacerle la conversion hash)
	void addSong(cancion s, artista a, int d) {
		if (canciones.count(s))
			throw std::domain_error("La cancion ya esta en el ipod");

		contenido nueva;
		nueva.art = a;
		nueva.playlist = playlist.end();
		nueva.played = played.end();
		nueva.duracion = d;
		canciones[s] = nueva;
	}

	//Constante
	void addToPlaylist(cancion s) {
		auto it = canciones.find(s);
		if (it == canciones.end())
			throw std::domain_error("La cancion no esta en el ipod");
		if (it->second.playlist == playlist.end()) {
			it->second.playlist = playlist.insert(playlist.end(),s);
			duracion += it->second.duracion;
		}
	}
	
	//Constante
	cancion current() {
		if (playlist.empty())
			throw std::domain_error("La playlist esta vacia");
		return playlist.front();
	}

	//Constante
	string play() {
		string out = "";
		if (!playlist.empty()) {
			auto it = canciones.find(playlist.front());
			//La metemos en played(borrandola antes si ya estaba)
			//y la sacamos de playlist
			if (it->second.played != played.end())
				played.erase(it->second.played);
			it->second.played = played.insert(played.begin(), playlist.front());
			playlist.pop_front();
			it->second.playlist = playlist.end();
			//Ajustamos nueva duracion y obtenemos salida
			duracion -= it->second.duracion;
			out = it->first;
		}
		return out;
	}

	//Constante
	int totalTime() {
		return duracion;
	}

	//O(n) 
	list<cancion> recent(int n) {
		list<cancion> salida;
		list<cancion>::iterator it = played.begin();
		int i = 0;
		while (i < n && it != played.end()) {
			salida.push_back(*it);
			it++;
			i++;
		}
		return salida;
	}

	//Constante
	void deleteSong(cancion s) {
		auto it = canciones.find(s);
		if (it != canciones.end()) {
			if (it->second.playlist != playlist.end()) {
				playlist.erase(it->second.playlist);
				duracion -= it->second.duracion;
			}

			if (it->second.played != played.end())
				played.erase(it->second.played);

			canciones.erase(it);
		}
	}
};
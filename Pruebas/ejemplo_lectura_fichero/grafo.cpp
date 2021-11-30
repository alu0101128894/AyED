#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

typedef struct
{
	unsigned j_; // nodo
	int 	 c_; // atributo para expresar su peso, longitud, coste...
} ElementoLista;

typedef vector<ElementoLista> LA_nodo;

class GRAFO
{
private:
	unsigned n_;          // número de nodos o vértices
	unsigned m_;          // número de arcos o aristas
	unsigned dirigido_;   // almacena 0 si el grafo es no dirigido, 1 eoc
	vector<LA_nodo> LS_;  // lista de sucesores o de adyacencia
	vector<LA_nodo> LP_;  // lista de predecesores
public:
	GRAFO(const char* nombrefichero, int &errorapertura)
	{
	 	crear_grafo(nombrefichero, errorapertura);
	}

	void actualizar(const char* nombrefichero, int &errorapertura) 
	{
		crear_grafo(nombrefichero, errorapertura);
	}

	unsigned Es_dirigido() const;  //devuelve 0 si el grafo es no dirigido, 1 eoc
	void Info_Grafo() const;
	void Mostrar_Listas(int l) const;
	void ListaPredecesores() const;
	~GRAFO() {}
private:
	void crear_grafo(const char* nombrefichero, int &errorapertura)
	{
		ifstream is(nombrefichero);

		if (is.is_open()) {

			errorapertura = 0;
			clear();

			is >> n_;
			is >> m_;
			is >> dirigido_;

#ifdef DEPURANDO
			cout << "Leyendo grafo  : "<< nombrefichero << endl;
			cout << "Número de nodos: " << setw(2) << n_ << endl;
			cout << "Número de arcos: " << setw(2) << m_ << endl;
			
			if (dirigido_ == 1)
				cout << "Grafo DIRIGIDO" << endl;
			else
				cout << "Grafo NO DIRIGIDO" << endl;
#endif

			// Redimensionar LS_ y LP_

			int s,t;  // origen y destino de un arco

			for(int i = 0; i < m_; i++){
				
				is >> s;
				is >> t;
#ifdef DEPURANDO
				cout << " - cargando arco ( "<< setw(2) << s << "," << setw(2) << t << ")" << endl;
#endif
				// Hacer algo: crear listas
			}

#ifdef DEPURANDO
			cout << "Fin de la carga" << endl;
#endif
			is.close();
		} else
			errorapertura = 1;
	}

	void clear(void) {
		LS_.clear();
		LP_.clear();
	}
};

int main(void)
{
	int status = 0;
	GRAFO G("grafo1.gr", status);
	
	if (status == 1)
		cerr << "ERROR EN APERTURA" << endl;
}




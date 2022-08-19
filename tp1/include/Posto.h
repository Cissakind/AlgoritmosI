#include "Pessoa.h"
#include <vector>
using namespace std;

class Posto {
	
	int max_pessoas;
	int cord_x;
	int cord_y;
	int id;
	vector<Pessoa> pessoasAlocadas;

	public:
	Posto(int _id, int x, int y, int tam);
	int getX();
	int getY();
	void print();

	friend class Relacao;
};
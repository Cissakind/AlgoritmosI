#include <utility>
#include <list>
#include <iostream>
using namespace std;

class Pessoa {
	
	int idade;
	int cord_x;
	int cord_y;
	int id;
	
	list<pair<float,int>> preferencia_posto;

	public:
	Pessoa(int _id, int x, int y, int _idade);
	int getX();
	int getY();
	void set_preferencia_posto(list<pair<float,int>>  dist_id_posto);
	void Print();

	friend bool operator<(const Pessoa& p1, const Pessoa& p2)
	{
	    return ((p1.idade < p2.idade) || (p1.idade == p2.idade && p1.id > p2.id));
	}

	friend class Relacao;
};
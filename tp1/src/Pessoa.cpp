#include "Pessoa.h"

Pessoa::Pessoa(int _id, int x, int y, int _idade)
{
	idade = _idade;
	cord_x = x;
	cord_y = y;
	id = _id;
}

int Pessoa::getX()
{
	return cord_x;
}

int Pessoa::getY()
{
	return cord_y;
}

void Pessoa::set_preferencia_posto(list<pair<float,int>>  dist_id_posto)
{
	preferencia_posto =  dist_id_posto;
}

void Pessoa::Print()
{
	cout << id << " ";
}


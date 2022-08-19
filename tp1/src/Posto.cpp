#include "Posto.h"

Posto::Posto(int _id, int x, int y, int tam)
{
	max_pessoas = tam;
	cord_x = x;
	cord_y = y;
	id = _id;
}

int Posto::getX()
{
	return cord_x;
}

int Posto::getY()
{
	return cord_y;
}

void Posto::print()
{
	int tam = pessoasAlocadas.size();
	for(int i = 0; i < tam ; i ++)
	{
		pessoasAlocadas[i].Print();
	}
	cout << endl;
}
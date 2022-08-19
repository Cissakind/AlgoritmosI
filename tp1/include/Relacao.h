#include "Posto.h"
#include <iostream>
#include <stack>
using namespace std;

class Relacao {
	vector<Pessoa> ordem;

	public:
	void casamento(vector<Pessoa> &lista_pessoas, vector<Posto> &lista_posto);
	bool proposta(Pessoa &pessoa, vector<Posto> &lista_posto);
};
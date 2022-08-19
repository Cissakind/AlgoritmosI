#include "Relacao.h"
#include <algorithm>


// executa a proposta de uma pessoa a um posto específico
bool Relacao::proposta(Pessoa &pessoa, vector<Posto> &lista_posto)
{
	int id_posto = pessoa.preferencia_posto.front().second;
	int tam = lista_posto[id_posto].pessoasAlocadas.size();

	if(tam < lista_posto[id_posto].max_pessoas)
	{
		pessoa.preferencia_posto.pop_front();
		lista_posto[id_posto].pessoasAlocadas.push_back(pessoa);
		return true;
	}
	return false;
}

//loop principal, passa por cada pessoa e realiza as propostas na ordem de preferência
void Relacao::casamento(vector<Pessoa> &lista_pessoas, vector<Posto> &lista_posto)
{
	while(!lista_pessoas.empty())
	{
		Pessoa &pessoa = lista_pessoas[lista_pessoas.size()-1];

		if(!proposta(pessoa, lista_posto))
		{
			pessoa.preferencia_posto.pop_front();
			if(pessoa.preferencia_posto.empty())
				lista_pessoas.erase(lista_pessoas.end());
		}
		else
		{
			lista_pessoas.erase(lista_pessoas.end());
		}
	}
	
	int tam = lista_posto.size();
	for(int i = 0; i < tam; i++)
	{
		if(!lista_posto[i].pessoasAlocadas.empty())
		{
			cout << i << endl;
			lista_posto[i].print();
		}
	}
}

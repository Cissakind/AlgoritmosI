#include <iostream>
#include <string>
#include <math.h>
#include "Relacao.h"
#include <algorithm>
using namespace std;

void leArquivo(vector<Pessoa> &lista_pessoas, vector<Posto> &lista_postos);
void caclula_lista_proximidade(Pessoa &pessoa, vector<Posto> lista_postos);
float calcula_dist(Pessoa pessoa, Posto posto);

int main() 
{
    vector<Pessoa> lista_pessoas;
    vector<Posto> lista_postos;
    leArquivo(lista_pessoas, lista_postos);
    sort(lista_pessoas.begin(), lista_pessoas.end());

    Relacao novaRelacao;
    novaRelacao.casamento(lista_pessoas, lista_postos);
}

void leArquivo(vector<Pessoa> &lista_pessoas, vector<Posto> &lista_postos)
{
    
    int num_postos;
    cin >> num_postos;
    
    int lotacao_max, cord_x, cord_y;
    for(int i = 0; i < num_postos; i++)
    {

        cin >> lotacao_max >> cord_x >> cord_y;
        Posto novoPosto = Posto(i, cord_x, cord_y, lotacao_max);
        lista_postos.push_back(novoPosto);
    }

    int num_pessoas;
    cin >> num_pessoas;

    int idade;
    for(int i = 0; i < num_pessoas; i++)
    {
        cin >> idade >> cord_x >> cord_y;
        Pessoa novaPessoa = Pessoa(i, cord_x, cord_y, idade);
        caclula_lista_proximidade(novaPessoa, lista_postos);
        lista_pessoas.push_back(novaPessoa);
    }
 }

 void caclula_lista_proximidade(Pessoa &pessoa, vector<Posto> lista_postos)
 {
    int tam = lista_postos.size();
    float dist;
    list<pair<float,int>> dist_id_posto;

    for(int i = 0; i < tam; i++)
    {
        dist = calcula_dist(pessoa, lista_postos[i]);
        dist_id_posto.push_back(make_pair(dist, i));
    }
    dist_id_posto.sort();
    pessoa.set_preferencia_posto(dist_id_posto);
}

 float calcula_dist(Pessoa pessoa, Posto posto)
 {
    return sqrt(pow(pessoa.getX() - posto.getX(), 2) +
                pow(pessoa.getY() - posto.getY(), 2));
 }
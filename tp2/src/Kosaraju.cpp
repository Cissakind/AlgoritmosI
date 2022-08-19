#include<bits/stdc++.h>
#include <iostream>
#include "Kosaraju.h"
using namespace std;

void Kosaraju::first_dfs(int v, vector<int> graph[],  vector<int> &explored, int inicio[], int fim[], int antecessor[], int &tempo)
{
    for (auto w : graph[v]) if(explored[w] == -1)
    {
    	tempo++;
        explored[w] = 0;
        antecessor[w] = v;
        inicio[w] = tempo;
        first_dfs(w, graph, explored, inicio, fim, antecessor, tempo);
    }
    tempo++;
    fim[v] = tempo;
    explored[v] = 1;
}

void Kosaraju::second_dfs(int v, vector<int> graph[],  vector<int> &component, int new_component_index)
{   
    for (auto w : graph[v]) if(component[w] == -1)
    {
        component[w] = new_component_index;
        second_dfs(w, graph, component, new_component_index);
    }
    component[v] = new_component_index;
}


void Kosaraju::alg_Kosaraju(int n, vector<int> g[], vector<int> &component, int &new_component_index)
{
    vector<int> g_reverso[n];
    vector<int> explored(n,-1);
    int inicio[n];
    int fim[n];
    int antecessor[n];
    int tempo = 0;
    
    // roda BFS e registra tempo de término
    for(int i = 0; i < n; i ++)
    {
        if(explored[i] == -1)
        {
            tempo++;
            explored[i] = 0;
            inicio[i] = tempo;
            first_dfs(i, g, explored, inicio, fim, antecessor, tempo);
        }
    }

    // inverte o grafo
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < int(g[i].size()); j++)
        {
            g_reverso[g[i][j]].push_back(i);
        }
    }

    // ordena os vértice na ordem em que a segunda BFS deve ser feita
    map<int, int, greater<int>> nova_ordem;
    for(int i = 0; i < n; i++)
    {
        nova_ordem.insert(make_pair(fim[i], i));
    }
    
    // realiza a segunda BFS, registrando o índice do componente do vértice
    for (auto i : nova_ordem)
    {
        if(component[i.second] == -1)
        {
            new_component_index++;
            component[i.second] = new_component_index;
            second_dfs(i.second, g_reverso,  component, new_component_index);
        }
    }
}

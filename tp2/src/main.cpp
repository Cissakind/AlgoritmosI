#include<bits/stdc++.h>
#include "Kosaraju.h"
#include <codecvt>
#include <cstring>
using namespace std;

void leGrafo(vector<int> g[], int arestas);
int count_needed_edges(int n, int new_compenent_index, vector<int> component, vector<int> g[]);

int main()
{

	int n, m; cin >> n >> m;
	vector<int> g[n];
	leGrafo(g, m);

	int new_compenent_index = -1;
	vector<int> component(n,-1);
	Kosaraju solver;
	solver.alg_Kosaraju(n, g, component, new_compenent_index);

	int result = count_needed_edges(n, new_compenent_index, component, g);
	cout << result << endl;
}

void leGrafo(vector<int> g[], int arestas)
{
	for(int i = 0; i < arestas; i++)
	{
		int u, v; cin >> u >> v; u--; v--;
		g[u].push_back(v);
	}
}

int count_needed_edges(int n, int new_compenent_index, vector<int> component, vector<int> g[])
{

	new_compenent_index++;
    int count_out_edges[new_compenent_index];
    int count_in_edges[new_compenent_index];
    memset(count_out_edges, 0, sizeof count_out_edges);
    memset(count_in_edges, 0, sizeof count_in_edges);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < int(g[i].size()); j++)
        {
            if(component[g[i][j]] != component[i])
            {
                count_in_edges[component[g[i][j]]]++;
                count_out_edges[component[i]]++;
            }
        }
    }

    int sum_out = 0;
    int sum_in = 0;
    for(int i = 0; i < new_compenent_index; i++)
    {
        if(count_in_edges[i] == 0)
            sum_in++;
        if(count_out_edges[i] == 0)
            sum_out++;
    }

    return max(sum_in, sum_out);
}
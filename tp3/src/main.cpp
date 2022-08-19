#include "VertexCoverTree.h"
#include "VertexCoverHeuristic.h"
#include <cstring>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

void leGrafo(vector<int> g[], int arestas, ifstream &read);

int main(int argc, char* argv[])
{
    string tarefa = argv[1];

	int n, m; 
    ifstream read; read.open(argv[2]);
    string graphInfo;
    getline (read, graphInfo);
    stringstream ss(graphInfo); ss >> n >> m;

    vector<int> g[n];
    leGrafo(g, m, read);
    read.close();

    if(tarefa == "tarefa1")
    {
        VertexCoverTree newTask1;
        newTask1.minVertexCover(g, n);
    }
    else if (tarefa == "tarefa2")
    {
       VertexCoverHeuristic newTask2;
       newTask2.simpleVertexCover(g, n);
    }
}


void leGrafo(vector<int> g[], int arestas, ifstream &read)
{   
    string graphInfo;
    int u, v;

	for(int i = 0; i < arestas; i++)
	{  
        getline(read, graphInfo);
        stringstream ss(graphInfo); ss >> u >> v;
		g[u].push_back(v);
        g[v].push_back(u);
	}
}

#include<bits/stdc++.h>
#include <iostream>
using namespace std;

class Kosaraju {

public:
	void first_dfs(int v, vector<int> graph[],  vector<int> &explored, int inicio[], int fim[], int antecessor[], int &tempo);
	void second_dfs(int v, vector<int> graph[],  vector<int> &explored, int novo_index);
	void alg_Kosaraju(int n, vector<int> g[], vector<int> &component, int &new_node_index);
};
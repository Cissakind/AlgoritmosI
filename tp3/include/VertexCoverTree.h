#include<bits/stdc++.h>
#include <iostream>
using namespace std;

class VertexCoverTree {

public:
	
	int opt(vector<int> g[], int x, int inc[], int exc[], int visited[]);
	void graphToTree(vector<int> g[], vector<int> tree[], int v, int n);
	void minVertexCover(vector<int> g[], int n);
};
#include<bits/stdc++.h>
#include <iostream>
#include "VertexCoverHeuristic.h"
using namespace std;

void VertexCoverHeuristic::simpleVertexCover(vector<int> g[], int n)
{   
	vector<int> solution_set;
    int visited[n];
    memset(visited, 0, sizeof(visited));

    int sum_vertices = 0;
    for(int i = 0; i < n; i++)
    {
        if(visited[i] == 0)
        {
        	if(int(g[i].size()) == 0)
            {
                sum_vertices += 1;
                solution_set.push_back(i);
                visited[i] = 1;
            }

            else
            {
                for(int j = 0; j < int(g[i].size()); j++)
                {
                	if(visited[g[i][j]] == 0)
                	{
                		solution_set.push_back(i);
                		solution_set.push_back(g[i][j]);
                		sum_vertices += 2;
                		visited[g[i][j]] = 1;
                		break;
                	}
                }

                visited[i] = 1;
            }
        }
    }

    cout << sum_vertices << endl;
    sort(solution_set.begin(), solution_set.end());
    for(int i = 0; i < int(solution_set.size()); i++)
    	cout << solution_set[i] << endl;
}
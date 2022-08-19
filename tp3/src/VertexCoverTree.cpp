#include<bits/stdc++.h>
#include <iostream>
#include "VertexCoverTree.h"
using namespace std;

void VertexCoverTree::graphToTree(vector<int> g[], vector<int> tree[], int v, int n)
{
    int visited[n];
    memset(visited, 0, sizeof(visited));
    
    for(int i = 0; i < n; i++)
    {
        if(visited[i] == 0)
        {
            list<int> queue;
 
            visited[v] = 1;
            queue.push_back(v);
         
            while(!queue.empty())
            {

                v = queue.front();
                queue.pop_front();

                for (int i = 0; i < int(g[v].size()); i++)
                {
                    if (!visited[g[v][i]])
                    {
                        tree[v].push_back(g[v][i]);
                        visited[g[v][i]] = 1;
                        queue.push_back(g[v][i]);
                    }
                }
            }
        }
    }
}

int VertexCoverTree::opt(vector<int> g[], int x, int inc[], int exc[], int visited[])
{
    visited[x] = 1;
    for(int i = 0; i < int(g[x].size()); i++)
    {
        opt(g, g[x][i], inc, exc, visited);
    }

    if(g[x].size() == 0)
    {
        inc[x] = 1;
        exc[x] = 0;
        return 0;
    }

    inc[x] = 1;
    for(int i = 0; i < int(g[x].size()); i++)
    {   
        inc[x] += min(inc[g[x][i]], exc[g[x][i]]);
    }

    exc[x] = 0;
    for(int i = 0; i < int(g[x].size()); i++)
    {   
        exc[x] += inc[g[x][i]];
    }
    return min(inc[x], exc[x]);
}

void VertexCoverTree::minVertexCover(vector<int> g[], int n)
{
    vector<int> tree[n];
    graphToTree(g, tree, 0, n);

    int inc[n];
    int exc[n];

    int visited[n];
    memset(visited, 0, sizeof(visited));

    int sum_opt = 0;
    for(int i = 0; i < n; i++)
    {
        if(visited[i] == 0)
        {
            if(int(g[i].size()) == 0)
                sum_opt += 1;
            else
                sum_opt += opt(tree, i, inc, exc, visited);
        }
    }

    cout << sum_opt;
}

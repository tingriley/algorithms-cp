#include<bits/stdc++.h>
using namespace std;
int t = 0;

void dfs(int u, int p, vector<vector<int>>&g, vector<int>& mark, vector<int>& d, vector<int>& low){
    mark[u] = 1;
    low[u] = d[u] = t++; 
    for(auto v:g[u]){
        if(!mark[v]){
            dfs(v, u, g, mark, d, low);
            low[u] = min(low[u], low[v]);
            if(low[v] > d[u])
                cout << "(" << u << "," << v << ") as an bridge" << endl;
        }
        else if(v!=p){
            low[u] = min(low[u], d[v]);
    }
        }
}

int main()
{
    int n = 4;
    vector<vector<int>>edges={{0, 1},{1, 2}, {2, 0}, {1,3}};
    vector<vector<int>>g(n);
    vector<int>mark(n, 0);
    vector<int>low(n, 0);
    vector<int>v(n, 0);
    vector<int>d(n, 0);


    for(auto &e:edges){
        int x = e[0];
        int y = e[1];
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(0, -1, g, mark, d, low);
    
}

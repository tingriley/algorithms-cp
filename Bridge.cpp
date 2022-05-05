#include<bits/stdc++.h>
using namespace std;
int t = 0;

void dfs(int u, vector<vector<int>>&g, vector<int>& mark, vector<int>& d, vector<int>& low, vector<int>& pred){
    mark[u] = 1;
    low[u] = d[u] = t++;
    for(auto v:g[u]){
        if(!mark[v]){
            pred[v] = u;
            dfs(v, g, mark, d, low, pred);
            low[u] = min(low[u], low[v]);
 
        }
        else if(v!=pred[u]){
            low[u] = min(low[u], d[v]);
        }
    }
}

int main()
{
    int n = 10;
    vector<vector<int>>edges={{0, 1},{1, 2}, {2, 3}, {2,4}, {3,5},{5,6},{1,4},{3,6},{0,7},{7,8},{8,9},{7,9}};
    vector<vector<int>>g(n);
    vector<int>mark(n, 0);
    vector<int>low(n, 0);
    vector<int>pred(n, -1);
    vector<int>v(n, 0);
    vector<int>d(n, 0);

    for(auto &e:edges){
        int x = e[0];
        int y = e[1];
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(0, g, mark, d, low, pred);
    for(int i = 0; i < n; i++){
        int u = pred[i];
        if(u!=-1 && d[i] == low[i])
            cout << "(" << u << ", " << i << ") as an bridge" << endl;
    }

}

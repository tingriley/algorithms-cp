#include <bits/stdc++.h>
 
using namespace std;
#define ll long long
 
#define ii pair<int, int>
#define f first
#define s second
#define mp make_pair
//https://cses.fi/problemset/task/1668
//CSES Building Teams
bool bipartite = true;
void dfs(vector<vector<int>> &g, vector<int> &v, vector<int> &color, int u, int c){
    v[u] = 1;
    color[u] = c;
    for(int i = 0; i < g[u].size(); i++){
        int node = g[u][i];
        if(!v[node]){
            dfs(g, v, color, node, !color[u]);
        }
        else{
            bipartite &= (color[u]!=color[node]);
        }
    }
}
 
void solve(){
    int n, k; cin >> n >> k;
    int ans = 0;
    vector<int> result;
    vector<vector<int>> g(n+1, vector<int>());
    vector<int> color(n+1, 0);
    vector<int> v(n+1, 0);
    bipartite = true;
    
    for(int i = 0; i < k; i++){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    for(int i = 1; i <= n; i++){
        if(!v[i]){
            dfs(g, v, color, i, 1);
        }
    }
 
    if(bipartite){
        for(int i = 1; i <= n; i++){
            cout << color[i] + 1 << " ";
        }
    }
    else{
        cout << "IMPOSSIBLE";
    }
    cout << endl;
}
 
int main() {
    
    solve();
    
    
    return 0;
}
#include <bits/stdc++.h>
 
using namespace std;
#define ll long long
 
#define ii pair<int, int>
#define f first
#define s second
#define mp make_pair

void dfs(vector<vector<int>> &g, vector<int> &v, int u){
    v[u] = 1;
    for(int i = 0; i < g[u].size(); i++){
        int node = g[u][i];
        if(!v[node]){
            dfs(g, v, node);
        }
    }
}
 
void solve(){
    int n, k; cin >> n >> k;
    int ans = 0;
    vector<int> result;
    vector<vector<int>> g(n+1, vector<int>());
    vector<int> v(n+1, 0);
    
    for(int i = 0; i < k; i++){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    for(int i = 1; i <= n; i++){
        if(!v[i]){
            result.push_back(i);
            dfs(g, v, i);
        }
    }
 
    cout << result.size()-1 << endl;
    for(int i = 0; i < result.size()-1;i++){
        cout << result[i] << " " << result[i+1] << endl;
    }
    
    
}
 
int main() {
    
    solve();
    
    
    return 0;
}
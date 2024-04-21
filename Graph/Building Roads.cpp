#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ff first
#define ss second
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define int long long int 
#define INF 1000000000000000
 
#define MAXN 202020
 
vector<vector<int>>adj(MAXN);
vector<int>vis(MAXN, 0);
 
void dfs(int node){
    vis[node] = 1;
    for(auto currN: adj[node]){
        if(!vis[currN]){
            dfs(currN);
        }
    }
}
 
int32_t main(){
    // Time taken to solve:- 20mins 14sec
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, m; 
    cin>>n>>m;
    
    while(m--){
        int a, b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector<int> bridges;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            bridges.push_back(i);
            dfs(i);
        }
    }
 
    cout<<bridges.size()-1<<endl;
    for(int i=0;i<bridges.size()-1;i++){
        cout<<bridges[i]<<" "<<bridges[i+1]<<endl;
    }
    return 0;
}

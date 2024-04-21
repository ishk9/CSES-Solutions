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
vector<vector<int>> adj(MAXN);
vector<int> vis(MAXN, 0);
 
vector<int> parent(MAXN, -1);
 
int32_t main(){
    // Time taken to solve:- 27mins 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, m; 
    cin>>n>>m;
    
    while(m--){
        int a, b;cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
 
    queue<int> q;
    q.push(1);
    vis[1] = 1;
 
    while(!q.empty()){
        int node = q.front();
        q.pop();
 
        if(node == n) break;
 
        for(auto &nod: adj[node]){
            if(!vis[nod]){
                q.push(nod);
                vis[nod] = 1;
 
                parent[nod] = node;
            }
        }
    }
    
    if(!vis[n]){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    
    vector<int> path;
    int node = n;
 
    while(node != -1){
        path.pb(node);
        node = parent[node];
 
    }
    reverse(path.begin(), path.end());
    cout<<path.size()<<endl;
    for(auto i:path) cout<<i<<" ";
 
    return 0;
}
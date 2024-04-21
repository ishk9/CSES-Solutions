#include <bits/stdc++.h>
 
#define pb push_back
#define ff first
#define ss second
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define int long long int 
#define INF 1000000000000000
 
using namespace std;
 
 
int32_t main(){
    int n, m; cin>>n>>m;
    
    vector<pair<int, int>> adj[n];
    while(m--){
        int a, b, c; cin>>a>>b>>c;
        a--;b--;
        adj[a].push_back({b, c});
    }
    vector<int> dist(n, INF);
    dist[0] = 0;
 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
 
    
    while(!pq.empty()){
        int node = pq.top().ss;
        int w = pq.top().ff;
        pq.pop();
 
        if (w > dist[node]) continue;
 
        for(auto &nod: adj[node]){
            int currNode = nod.ff;
            int currDist = nod.ss;
 
            if(w + currDist < dist[currNode]){
                dist[currNode] = w + currDist;
                pq.push({dist[currNode], currNode});
            }
        }
 
    }
 
    for(int i=0;i<n;i++) cout<<dist[i]<<" ";
 
    return 0;
}
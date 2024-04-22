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
int n, m;


vector<int> dijkstra(int src, vector<pair<int, int>> adj[]) {
    vector<int> dist(n+1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    dist[src] = 0;

    vector<int> vis(n+1, 0);

    while (!pq.empty()) {
        int node = pq.top().ss;
        int wght = pq.top().ff;
        pq.pop();

        if(vis[node]) continue;
        vis[node] = 1;
        for (auto &ele : adj[node]) {
            int currNode = ele.ff;
            int currWght = ele.ss;

            if (wght + currWght < dist[currNode]) {
                dist[currNode] = wght + currWght;
                pq.push({dist[currNode], currNode});
            }
        }
    }
    return dist;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;


    vector<pair<int, int>> adj1[n+1];
    vector<pair<int, int>> adj2[n+1];



    vector<vector<int>> edges;
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges.pb({a, b, w});
        adj1[a].pb({b, w});
        adj2[b].pb({a, w});
    }

    vector<int> fromSrc = dijkstra(1, adj1);
    vector<int> fromDest = dijkstra(n, adj2);


    int ans = INF;
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        ans = min(ans, fromSrc[u] + fromDest[v] + w / 2);
    }
    cout<<ans<<endl;
    return 0;
}

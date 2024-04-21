#include <bits/stdc++.h>
 
#define pb push_back
#define ff first
#define ss second
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
 
using namespace std;
 
bool isValid(int n, int m, int i, int j){
    if(i < 0 || j < 0 || i >= n || j >= m) return false;
    return true;
}
 
void dfs(vector<vector<char>> &mp, int n, int m, int i, int j){
    mp[i][j] = '#';
    int dirs[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
 
    for(auto &dir: dirs){
        int n_i = i + dir[0];
        int n_j = j + dir[1];
        if(isValid(n, m, n_i, n_j) && mp[n_i][n_j] != '#')
            dfs(mp, n, m, n_i, n_j);
    }
}
 
int main(){
    int n, m; cin>>n>>m;
 
    vector<vector<char>> mp(n, vector<char>(m, '.'));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char t;cin>>t;
            mp[i][j] = t;
        }
    }
 
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mp[i][j] != '#'){
                dfs(mp, n, m, i, j);
                ans += 1;
            }
        }
    }    
 
    cout<<ans<<endl;
 
    return 0;
}
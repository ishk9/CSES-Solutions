#include <bits/stdc++.h>
 
#define pb push_back
#define ff first
#define ss second
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
// #define int long long int 
#define INF 1000000000000000
 
using namespace std;
 
bool isValid(int i, int j, int n, int m){
    if(i < 0 || j < 0 || i >= n || j >= m) return false;
    return true;
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, m; cin>>n>>m;
    
    vector<vector<char>> grid(n, vector<char>(m, '*'));
    vector<vector<int>> vis(n, vector<int> (m, 0));
 
    queue<pair<int, int>> q;
 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char t;cin>>t;
            grid[i][j] = t;
            if(t == 'A') {
                q.push({i, j});
                vis[i][j] = 1;
            }
        }
    }    
    bool found = false;
    int dir[4][2] { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
 
    
 
    vector<vector<char>> dirGrid(n, vector<char> (m, '*'));
    string ans = "";
 
    while(!q.empty()){
        int i = q.front().ff;
        int j = q.front().ss;
        q.pop();
 
        if(grid[i][j] == 'B'){
            found = true;
            
            while(true){
                ans += dirGrid[i][j];
 
                if(dirGrid[i][j] == 'U') i++;
                else if(dirGrid[i][j] == 'D') i--;
                else if(dirGrid[i][j] == 'L') j++;
                else if(dirGrid[i][j] == 'R') j--;
                
                if(grid[i][j] == 'A') break;
            }
            break;
        }
    
 
        for(int ind=0;ind<4;ind++){
            int n_i = i + dir[ind][0];
            int n_j = j + dir[ind][1];
 
            if(isValid(n_i, n_j, n, m) && !vis[n_i][n_j] && grid[n_i][n_j] != '#'){
 
                if(ind == 0)      dirGrid[n_i][n_j] = 'U', vis[n_i][n_j] = 1;
                else if(ind == 1) dirGrid[n_i][n_j] = 'D', vis[n_i][n_j] = 1;
                else if(ind == 2) dirGrid[n_i][n_j] = 'R', vis[n_i][n_j] = 1;
                else if(ind == 3) dirGrid[n_i][n_j] = 'L', vis[n_i][n_j] = 1;
 
                q.push({n_i, n_j});
            }
        }
    }
    if(!found) cout<<"NO"<<endl;
    else{
        reverse(ans.begin(), ans.end());
        cout<<"YES"<<endl;
        cout<<ans.length()<<endl;
        cout<<ans<<endl;
    }
    return 0;
}
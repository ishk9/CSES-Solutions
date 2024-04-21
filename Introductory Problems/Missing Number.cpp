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
 
 
int32_t main(){
    // Time taken to solve:- 15mins 10sec 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n; 
    cin>>n;
    vector<int> inp;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        inp.pb(x);
    }
    vector<int> v(n+1, 0);
    for(auto i:inp) v[i] = 1;
    
    for(int i=1;i<=n;i++){
        if(v[i] == 0) {
            cout<<i<<endl;
            break;
        }
    }
 
    return 0;
}
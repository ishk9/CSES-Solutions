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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n;cin>>n;

    int curr = 0;
    for(int i=1;i<n;i++){
        int x;cin>>x;
        curr += x;
    }

    int total = (n * (n + 1)) / 2;
    cout<<total - curr<<endl;

    return 0;
}
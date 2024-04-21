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

    while(n != 1){
        cout<<n<<" ";   
        if(n % 2 == 0){
            n = n/2;
        }
        else{
            n = (3 * n) + 1;
        }
    }
    cout<<1<<endl;
    return 0;
}
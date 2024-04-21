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

    vector<int> nums;
    for(int i=0;i<n;i++){
        int t;cin>>t;
        nums.pb(t);
    }
    
    int op = 0;
    int mx = nums[0];

    for(int i=1;i<n;i++){
        op += max(0LL, (mx - nums[i]));
        mx = max(mx, nums[i]);
    }
    cout<<op<<endl;

    return 0;
}
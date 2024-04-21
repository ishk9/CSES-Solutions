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
 
    string s;cin>>s;
    int n = s.length();

    int mxLen = 0;
    int i = 0, j = 0;

    unordered_map<char, int> mp;

    while(j < n){
        mp[s[j]]++;
        while(mp.size() > 1){
            mp[s[i]]--;
            if(mp[s[i]] == 0) mp.erase(s[i]);
            i++;
        }
        mxLen = max(mxLen, j - i + 1);
        j++;

    }   
    cout<<mxLen<<endl;
    return 0;
}
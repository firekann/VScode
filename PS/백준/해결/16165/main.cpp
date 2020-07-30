#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define X first
#define Y second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;
typedef long long ll;
const int dx[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

int main(){
    fastio
    int n, m;
    cin>>n>>m;
    map<string, vector<string>> mpt;
    map<string, string> mp;
    for(int i=0; i<n; i++){
        string team;
        int tmp;
        cin>>team>>tmp;
        vector<string> tmpv(tmp);
        for(auto &itr:tmpv) cin>>itr;
        sort(all(tmpv));
        for(auto itr:tmpv) mp[itr]=team;
        mpt[team]=tmpv;
    }
    for(;m--;){
        int op;
        string s;
        cin>>s>>op;
        if(op) cout<<mp[s]<<"\n";
        else for(auto i:mpt[s]) cout<<i<<"\n";
    }
}
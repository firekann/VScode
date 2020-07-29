#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define X first
#define Y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;
typedef long long ll;
const int dx[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

int main(){
    fastio
    int n, m;
    cin>>n>>m;
    vector<string> v(n);
    for(int i=0; i<n; i++){
        vector<pair<int, int>> tmp;
        for(int j=0; j<m; j++){
            int t;
            cin>>t;
            tmp.push_back({t, j});
        }
        sort(all(tmp));
        for(auto itr:tmp) v[i]+=to_string(itr.Y)+"/";
    }
    sort(all(v));
    int cnt=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(v[i]==v[j]) cnt++;
        }
    }
    cout<<cnt;
}
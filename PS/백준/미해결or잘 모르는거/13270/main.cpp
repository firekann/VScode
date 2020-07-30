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

vector<int> v;
int n;
int minv=1e9, maxv=-1e9;

void dfs(int a, int b, int idx, int vmax){
    if(idx>=vmax) return;
    if(a>=n){
        if(a==n) minv=min(minv, b), maxv=max(maxv, b);
        return;
    }
    for(int i=0; i<=n/v[idx]; i++){
        dfs(a+v[idx]*i, b+v[idx-1]*i, idx+1, vmax);
    }
}

int main(){
    fastio
    cin>>n;
    v.pb(1);
    v.pb(2);
    for(int i=2; 1; i++){
        v.pb(v[i-2]+v[i-1]);
        if(v[i]>=n) break;
    }
    dfs(0, 0, 1, sz(v));
    cout<<minv<<" "<<maxv;
}
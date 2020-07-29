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

typedef struct roll{
    int x, w, f, c, e;
} roll;
vector<vector<roll>> vr(1010);
int ans=-1e9;
int l, n, b;

int main(){
    fastio
    cin>>l>>n>>b;
    for(int i=0; i<n; i++){
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        vr[a].push_back({a, b, c, d, a+b});
    }
    //dfs(0, 0, 0);
    if(ans==-1e9) cout<<"-1";
    else cout<<ans;
}
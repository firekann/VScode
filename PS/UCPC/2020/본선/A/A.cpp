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
#define mid ((l+r)>>1)

using namespace std;
typedef long long ll;
const int dx[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

vector<vector<int>> edge(100100);
vector<int> visit(100100);
int n, s, d;

int dfs(int root, int cur){
    if(cur!=s&&sz(edge[cur])==1){
        visit[cur]=0;
        return 0;
    }
    for(auto i:edge[cur]){
        if(i==root) continue;
        int tmp=dfs(cur, i)+1;
        visit[cur]=max(visit[cur], tmp);
    }
    return visit[cur];
}

int main(){
    fastio
    cin>>n>>s>>d;
    for(int i=0; i<n-1; i++){
        int a, b;
        cin>>a>>b;
        edge[a].pb(b);
        edge[b].pb(a);
    }
    visit[s]=dfs(-1, s);
    int ans=-2;
    for(int i=1; i<=n; i++){
        if(visit[i]>=d) ans+=2;
    }
    ans=ans==-2?0:ans;
    cout<<ans;
}
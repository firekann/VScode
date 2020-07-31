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

int n, m;
vector<string> v;
int ans;

void bfs(){
    queue<pii> qq;
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) if(v[i][j]=='L') qq.push({i, j});
    while(!qq.empty()){
        pii tmp=qq.front();
        qq.pop();
        int sy=tmp.X;
        int sx=tmp.Y;
        vector<vector<int>> dist(n);
        for(auto &i:dist) i.resize(m, 0);        
        queue<pii> q;
        q.push({sy, sx});        
        while(!q.empty()){
            tmp=q.front();
            q.pop();
            int y=tmp.X;
            int x=tmp.Y;
            for(int i=0;i<4;i++){
                int ty=y+dy[i];
                int tx=x+dx[i];
                if(ty<0||ty>=n||tx<0||tx>=m) continue;                
                if(v[ty][tx]=='W'||(sy==ty&&sx==tx)) continue;
                if(!dist[ty][tx]||dist[ty][tx]>dist[y][x]+1){
                    dist[ty][tx]=dist[y][x]+1;
                    q.push({ty, tx});
                }
            }
        }
        for(auto i:dist) for(auto j:i) if(j) ans=max(ans, j);
    }
}

int main(){
    fastio
    cin>>n>>m;
    v.resize(n);
    for(auto &i:v) cin>>i;
    bfs();
    cout<<ans;
}
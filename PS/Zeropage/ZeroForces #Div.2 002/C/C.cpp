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

const int tdx[] = { -2, -2, 0, 0, 2, 2 };
const int tdy[] = { -1, 1, -2, 2, -1, 1 };

bool visit[202][202];
int r1, c1, r2, c2, n;

void bfs(int a, int b){
    queue<pair<pii, int>> q;
    q.push({{a, b}, 0});
    visit[a][b]=true;
    while(!q.empty()){
        pair<pii, int> tmp=q.front();
        q.pop();
        int x=tmp.X.X;
        int y=tmp.X.Y;
        int dist=tmp.Y;
        if(x==r2&&y==c2){
            cout<<dist;
            return;
        }
        for(int i=0; i<6; i++){
            int tx=x+tdx[i];
            int ty=y+tdy[i];
            if(tx<0||tx>=n||ty<0||ty>=n) continue;
            if(!visit[tx][ty]){
                visit[tx][ty]=true;
                q.push({{tx, ty}, dist+1});
            }
        }
    }
    cout<<-1;
    return;
}

int main(){
    fastio
    cin>>n;
    cin>>r1>>c1>>r2>>c2;
    bfs(r1, c1);
}
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
const int dx[]={ -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[]={ 0, 1, 0, -1, 1, 1, -1, -1 };

int n, m, t, ans;
vector<vector<int>> mp;
vector<vector<bool>> visit;
vector<vector<bool>> visit2;

void bfs() {
    queue<pair<pii, pair<int, bool>>> q;
    q.push({ { 0, 0 }, { 0, false } });
    visit[0][0]=true;
    while (!q.empty()) {
        int x=q.front().X.X;
        int y=q.front().X.Y;
        int dist=q.front().Y.X;
        bool sod=q.front().Y.Y;
        q.pop();
        if (mp[x][y]==2) sod=true;
        for (int i=0; i<4; i++) {
            int tx=x+dx[i];
            int ty=y+dy[i];
            if (tx<0||tx>=n||ty<0||ty>=m||(!sod&&visit[tx][ty])||(sod&&visit2[tx][ty])||(!sod&&mp[tx][ty]==1)||dist>=t) continue;
            if (tx==n-1&&ty==m-1) {
                ans=dist+1;
                return;
            }
            visit[tx][ty]=true;
            visit2[tx][ty]=sod?true:false;
            q.push({ { tx, ty }, { dist+1, sod } });
        }
    }
}

int main() {
    fastio;
    cin>>n>>m>>t;
    mp.resize(n, vector<int>(m));
    visit.resize(n, vector<bool>(m, false));
    visit2.resize(n, vector<bool>(m, false));
    for (auto &i:mp) for (auto &j:i) cin>>j;
    bfs();
    if (ans&&ans<=t) cout<<ans;
    else cout<<"Fail";
}
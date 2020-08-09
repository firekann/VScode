#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
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
//const int dx[] ={ -1, 0, 1, 0, -1, 1, 1, -1 };
//const int dy[] ={ 0, 1, 0, -1, 1, 1, -1, -1 };

const int dx[] ={ -1, 0, 1, 0, 0, 0 };
const int dy[] ={ 0, 1, 0, -1, 0, 0 };
const int dz[] ={ 0, 0, 0, 0, 1, -1 };

int n, m, h, ans;
vector<vector<vector<int>>> vv;
vector<vector<vector<bool>>> visit;

void bfs() {
    queue<pair<pii, int>> q;
    int idx=0;
    for (int k=0; k<h; k++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                visit[k][i][j]=false;
                if (vv[k][i][j]==1) {
                    q.push({ { i, j }, k });
                    idx++;
                }
            }
        }
    }
    while (!q.empty()) {
        int cnt=0;
        bool ck=false;
        for (int i=0; i<idx; i++) {
            pair<pii, int> pos=q.front();
            q.pop();
            visit[pos.Y][pos.X.X][pos.X.Y]=true;
            for (int j=0; j<6; j++) {
                int x=pos.X.Y+dx[j];
                int y=pos.X.X+dy[j];
                int z=pos.Y+dz[j];
                if (x>=0&&x<m&&y>=0&&y<n&&z>=0&&z<h&&!visit[z][y][x]&&!vv[z][y][x]) {
                    ck=true;
                    vv[z][y][x]=1;
                    q.push({ { y, x }, z });
                    cnt++;
                }
            }
        }
        idx=cnt;
        if (ck) ans++;
    }
    return;
}

int main() {
    fastio;
    cin>>m>>n>>h;
    vv.resize(h);
    visit.resize(h);
    for (auto &i:vv) {
        i.resize(n, vector<int>(m));
        for (auto &j:i) {
            for (auto &k:j) cin>>k;
        }
    }
    for (auto &i:visit) i.resize(n, vector<bool>(m, false));
    bfs();
    for (int k=0; k<h; k++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (!visit[k][i][j]&&!vv[k][i][j]) {
                    cout<<"-1";
                    return 0;
                }
            }
        }
    }
    cout<<ans;
}
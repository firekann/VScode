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

int n, m, ans;
vector<vector<int>> vv;
vector<vector<bool>> visit;

void bfs(){
    queue<pii> q;
    int idx=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            visit[i][j]=false;
            if(vv[i][j]==1){
                q.push({i, j});
                idx++;
            }
        }
    }
    while(!q.empty()){
        int cnt=0;
        bool ck=false;
        for(int i=0; i<idx; i++){
            pii pos=q.front();
            q.pop();
            visit[pos.X][pos.Y]=true;
            for(int j=0; j<4; j++){
                int x=pos.Y+dx[j];
                int y=pos.X+dy[j];
                if(x>=0&&x<m&&y>=0&&y<n&&!visit[y][x]&&!vv[y][x]){
                    ck=true;
                    vv[y][x]=1;
                    q.push({y, x});
                    cnt++;
                }
            }
        }
        idx=cnt;
        if(ck) ans++;
    }
    return;
}

int main(){
    fastio
    cin>>m>>n;
    vv.resize(n);
    visit.resize(n);
    for(auto &i:vv){
        for(int j=0; j<m; j++){
            int tmp;
            cin>>tmp;
            i.pb(tmp);
        }
    }
    for(auto &i:visit) i.resize(m);
    bfs();
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visit[i][j]&&!vv[i][j]){
                cout<<"-1";
                return 0;
            }
        }
    }
    cout<<ans;
}
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

struct tree{
    int x, y, z;
};

int main(){
    fastio
    int n, m, k;
    cin>>n>>m>>k;
    vector<vector<int>> A(n+1, vector<int>(n+1, 0));
    vector<vector<int>> v=A;
    vector<int> age[11][11];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>A[i][j];
            v[i][j]=5;
        }
    }
    for(int i=0; i<m; i++){
        tree tmp;
        cin>>tmp.x>>tmp.y>>tmp.z;
        age[tmp.x][tmp.y].pb(tmp.z);
    }
    for(;k--;){
        vector<tree> dead;
        vector<tree> grow;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(age[i][j].empty()) continue;
                vector<int> tmpv;
                sort(all(age[i][j]));
                for(auto itr:age[i][j]){
                    int tmp=itr;
                    if(v[i][j]>=tmp){
                        v[i][j]-=tmp;
                        tmpv.pb(tmp+1);
                        if(!((tmp+1)%5)) grow.pb({i, j, tmp+1});
                    }
                    else dead.pb({i, j, tmp/2});
                }
                age[i][j]=tmpv;
            }
        }
        for(auto itr:dead){
            tree tmp=itr;
            v[tmp.x][tmp.y]+=tmp.z;
        }
        for(auto itr:grow){
            tree tmp=itr;
            for(int i=0; i<8; i++){
                int x=tmp.x+dx[i];
                int y=tmp.y+dy[i];
                if(x<1||x>n||y<1||y>n) continue;
                age[x][y].pb(1);
            }
        }
        for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) v[i][j]+=A[i][j];
    }
    int ans=0;
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) ans+=sz(age[i][j]);
    cout<<ans;
}
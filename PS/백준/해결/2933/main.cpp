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

int r, c;
char a[101][101];
bool visit[101][101];
vector<pair<int, int>> vp;
bool flag;

void dfs(int y, int x){
    if(y==r-1){flag=true; return;}
    for(int i=0; i<4; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<0||nx>=c||ny<0||ny>=r||visit[ny][nx]||a[ny][nx]=='.') continue;
        vp.push_back({ny, nx});
        visit[ny][nx]=true;
        dfs(ny, nx);
    }
}

int main(){
    fastio
    cin>>r>>c;
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) cin>>a[i][j];
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int t;
        cin>>t;
        int x, y;
        x=-1;
        y=r-t;
        if(i%2){
            for(int i=c-1; i>=0; i--){
                if(a[y][i]=='x'){
                    x=i;
                    break;
                }
            }
        }
        else{
            for(int i=0; i<c; i++){
                if(a[y][i]=='x'){
                    x=i;
                    break;
                }
            }
        }
        a[y][x]='.';
        if(x!=-1){
            for(int j=0; j<4; j++){
                int nx=x+dx[j];
                int ny=y+dy[j];
                if(nx<0||nx>=c||ny<0||ny>=r||a[ny][nx]=='.') continue;
                memset(visit, false, sizeof(visit));
                vp.clear();
                vp.push_back({ny, nx});
                visit[ny][nx]=true;
                flag=false;
                dfs(ny, nx);
                if(flag) continue;
                for(auto itr:vp) a[itr.X][itr.Y]='.';
                int len=0;
                for(int k=1; 1; k++){
                    for(auto itr:vp){
                        x=itr.Y;
                        y=itr.X+k;
                        if(y==r||a[y][x]=='x'){
                            len=k-1;
                            break;
                        }
                    }
                    if(len) break;
                }
                for(auto itr:vp) a[itr.X+len][itr.Y]='x';
            }
        }
    }
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++) cout<<a[i][j];
        cout<<"\n";
    }
}
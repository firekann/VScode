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
const int dx[] = { -1, 1, 0, 0, -1, 1, 1, -1 };
const int dy[] = { 0, 0, -1, 1, 1, 1, -1, -1 };

int ndx[] = { 0, 0, 0, 0 };
int ndy[] = { 0, 0, 0, 0 };

int n, m;
int dir=0;
int room[1000][1000];
int cnt=1;

int stx, sty;
void dfs(){
    int cntb=0;
    for(int i=0; i<4; i++){
        if(stx+ndx[i]<0||stx+ndx[i]>=n||sty+ndy[i]<0||sty+ndy[i]>=m) cntb++;
        else if(room[stx+ndx[i]][sty+ndy[i]]) cntb++;
    }
    if(cntb==4) return;
    if(stx+ndx[dir]<0||stx+ndx[dir]>=n||sty+ndy[dir]<0||sty+ndy[dir]>=m){
        dir++;
        dir%=4;
    }
    else if(room[stx+ndx[dir]][sty+ndy[dir]]==0){
        room[stx][sty]=cnt++;
        stx+=ndx[dir];
        sty+=ndy[dir];
    }
    else{
        dir++;
        dir%=4;
    }
    dfs();
}

int main(){
    fastio
    cin>>n>>m;
    int block;
    cin>>block;
    for(int i=0; i<block; i++){
        int a, b;
        cin>>a>>b;
        room[a][b]=-1;
    }
    cin>>stx>>sty;
    for(int i=0; i<4; i++){
        int tmp;
        cin>>tmp;
        ndx[i]=dx[tmp-1];
        ndy[i]=dy[tmp-1];
    }
    dfs();
    cout<<stx<<" "<<sty;
}
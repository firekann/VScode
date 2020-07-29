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

bool ck[52][52]={0};

void dfs(int x, int y){
    if(x>=0&&x<=50&&y>=0&&y<=50) ck[x][y]=0;
    else return;
    if(ck[x-1][y]) dfs(x-1, y);
    if(ck[x+1][y]) dfs(x+1, y);
    if(ck[x][y-1]) dfs(x, y-1);
    if(ck[x][y+1]) dfs(x, y+1);
    else return;
}

int main(){
    fastio
    int n;
    cin>>n;
    for(;n--;){
        int a, b, c;
        cin>>a>>b>>c;
        for(int i=1; i<=a; i++) for(int j=1; j<=b; j++) ck[j][i]=0;
        for(;c--;){
            int x, y;
            cin>>x>>y;
            ck[y+1][x+1]=1;
        }
        int cnt=0;
        for(int i=1; i<=a; i++){
            for(int j=1; j<=b; j++){
                if(ck[j][i]){
                    dfs(j, i);
                    cnt++;
                }
            }
        }
        cout<<cnt<<"\n";
    }
}
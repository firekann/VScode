#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long lli;

typedef struct{
	int x, y;
} offsets;
offsets moved[4]={
	{-1, 0},
	{0, 1},
	{1, 0},
	{0, -1},
};
typedef struct{
    int arr[8][8];
} Array;
Array a, b;
int n, m, ans=1e9;
bool visit[8][8][4];
vector<offsets> vp;
vector<int> v;

void dfs(int num){
    if(num==vp.size()){
        for(int i=0; i<v.size(); i++){
            int x=vp[i].x;
            int y=vp[i].y;
            for(int j=0; j<4; j++){
                if(visit[x][y][j]){
                    int nx=x+moved[(v[i]+j)%4].x;
                    int ny=y+moved[(v[i]+j)%4].y;
                    while(1){
                        if(b.arr[nx][ny]==6) break;
                        if(0>nx||nx>=n||0>ny||ny>=m) break;
                        if(b.arr[nx][ny]==0) b.arr[nx][ny]=-1;
                        nx+=moved[(v[i]+j)%4].x;
                        ny+=moved[(v[i]+j)%4].y;
                    }
                    
                }
            }
        }
        int s=0;
        for(int i=0; i<n; i++) for(int j=0; j<m; j++) s+=b.arr[i][j]==0?1:0;
        ans=min(ans, s);
        b=a;
        return;
    }
    for(int i=0; i<4; i++){
        v.push_back(i);
        dfs(num+1);
        v.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a.arr[i][j];
            if(0<a.arr[i][j]&&a.arr[i][j]<6) vp.push_back({i, j});
            if(a.arr[i][j]==1) visit[i][j][0]=1;
            else if(a.arr[i][j]==2) visit[i][j][0]=1, visit[i][j][2]=1;
            else if(a.arr[i][j]==3) visit[i][j][0]=1, visit[i][j][1]=1;
            else if(a.arr[i][j]==4) visit[i][j][0]=1, visit[i][j][1]=1, visit[i][j][2]=1;
            else if(a.arr[i][j]==5) visit[i][j][0]=1, visit[i][j][1]=1, visit[i][j][2]=1, visit[i][j][3]=1;
        }
    }
    b=a;
    dfs(0);
    cout<<ans;
}
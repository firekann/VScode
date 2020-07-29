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

int n;
int arr[100][100];
bool visit[100][100];

void dfs(int x, int y){
    if(visit[x][y]) return;
    visit[x][y]=true;
    for(int i=0; i<4; i++){
        if(x+dx[i]<n&&x+dx[i]>=0&&y+dy[i]<n&&y+dy[i]>=0) dfs(x+dx[i], y+dy[i]);
    }
}

int main(){
    fastio
    cin>>n;
    int maxh=-1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
            maxh=max(maxh, arr[i][j]);
        }
    }
    int ans=0;
    for(int h=0; h<maxh; h++){
        int cnt=0;
        for(int i=0; i<n; i++) memset(visit[i], false, n);
        for(int i=0; i<n; i++) for(int j=0; j<n; j++) if(arr[i][j]<=h) visit[i][j]=true;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(!visit[i][j]) dfs(i, j), cnt++;
        ans=max(ans, cnt);
    }
    cout<<ans;
}
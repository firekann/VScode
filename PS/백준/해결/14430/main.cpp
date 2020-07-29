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

int n, m;
int arr[300][300];
bool visit[300][300];
int f(int x, int y){
    if(x==n-1&&y==m-1) return arr[x][y];
    if(visit[x][y]) return arr[x][y];
    visit[x][y]=true;
    int a=0, b=0;
    if(x+1<n) a=f(x+1, y);
    if(y+1<m) b=f(x, y+1);
    return arr[x][y]+=max(a, b);
}

int main(){
    fastio
    cin>>n>>m;
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) cin>>arr[i][j];
    cout<<f(0, 0)<<"\n";
}
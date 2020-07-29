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
int a[20][20];

int f(int x, int y, int d1, int d2){
    if(x+d1>=n||y-d1<0) return 1e9;
    if(x+d2>=n||y+d2>=n) return 1e9;
    if(x+d1+d2>=n||y-d1+d2>=n) return 1e9;
    if(x+d2+d1>=n||y+d2-d1<0) return 1e9;
    int sum[5]={0,0,0,0,0};
    bool visit[20][20];
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) visit[i][j]=true;
    for(int i=0, t=0; i<x+d1; i++){
        if(i>=x) t++;
        for(int j=0; j<=y-t; j++) sum[0]+=a[i][j], visit[i][j]=false;
    }
    for(int i=0, t=0; i<=x+d2; i++){
        if(i>x) t++;
        for(int j=y+t+1; j<n; j++) sum[1]+=a[i][j], visit[i][j]=false;
    }
    for(int i=n-1, t=0; i>=x+d1; i--){
        if(i<x+d1+d2) t++;
        for(int j=0; j<y-d1+d2-t; j++) sum[2]+=a[i][j], visit[i][j]=false;
    }
    for(int i=n-1, t=0; i>x+d2; i--){
        if(i<=x+d1+d2) t++;
        for(int j=y-d1+d2+t; j<n; j++) sum[3]+=a[i][j], visit[i][j]=false;
    }
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) if(visit[i][j]) sum[4]+=a[i][j];
    sort(sum, sum+5);
    return sum[4]-sum[0];
}

int d(int x, int y){
    int ans=1e9;
    for(int i=1; i<=y; i++){
        for(int j=1; j<n-y; j++){
            int t=f(x, y, i, j);
            ans=min(ans, t);
        }
    }
    return ans;
}

int main(){
    fastio
    cin>>n;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin>>a[i][j];
    int ans=1e9;
    for(int i=0; i<n; i++){
        for(int j=1; j<n; j++){
            int t=d(i, j);
            ans=min(ans, t);
        }
    }
    cout<<ans;
}
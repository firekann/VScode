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

char mp[2048][4096];
int n;
void f(int r, int d){
    if(!d) return;
    int m=(1<<n)-2, h=(1<<d)-2;
    for(int i=0; i<=h; i++){
        int x=d&1?i:h-i;
        for(int j=m-h; j<=m+i; j++){
            if(j==m+i||j==m-i||i==h) mp[r+x][j]='*';
            else mp[r+x][j]=' ';
        }
    }
    f(d&1?r+(h>>1):r+1, d-1);
}

int main(){
    fastio
    cin>>n;
    f(0, n);
    for(int i=0; i<=(1<<n)-2; i++) cout<<mp[i]<<"\n";
}
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

using namespace std;
typedef long long ll;
const int dx[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

int main(){
    fastio;
    int n;
    cin>>n;
    n=1000-n;
    int cnt=0;
    if(n/500) cnt+=n/500, n%=500;
    if(n/100) cnt+=n/100, n%=100;
    if(n/50) cnt+=n/50, n%=50;
    if(n/10) cnt+=n/10, n%=10;
    if(n/5) cnt+=n/5, n%=5;
    if(n/1) cnt+=n/1, n%=1;
    cout<<cnt;
}
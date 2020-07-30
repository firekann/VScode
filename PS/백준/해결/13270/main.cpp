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

using namespace std;
typedef long long ll;
const int dx[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

int main(){
    fastio
    vector<int> v;
    int n;
    int minv, maxv;
    cin>>n;
    if(n%2) minv=(n+1)/2;
    else minv=n/2;
    if(n%3==2) maxv=2*(n/3)+1;
    else maxv=2*(n/3);
    cout<<minv<<" "<<maxv;
}
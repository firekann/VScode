#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
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
const int dx[] ={ -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[] ={ 0, 1, 0, -1, 1, 1, -1, -1 };

vector<int> v;
vector<vector<int>> dp;
int n;

int sol(int a, int b) {
    if (a==n) return 0;
    if (dp[a][b+1]==-1) dp[a][b+1]=min(sol(a+1, b)+(a?abs(v[a]-v[a-1]):0), sol(a+1, a-1)+(b<0?0:abs(v[a]-v[b])));
    return dp[a][b+1];
}

int main() {
    fastio;
    cin>>n;
    v.resize(n);
    for (auto &i:v) cin>>i;
    dp.resize(n+1, vector<int>(n+1, -1));
    cout<<sol(0, -1);
}
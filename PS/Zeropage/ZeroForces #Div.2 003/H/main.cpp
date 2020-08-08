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

const int mod=1e9+7;

vector<vector<ll>> f(vector<vector<ll>> a, vector<vector<ll>> b) {
    int size=sz(a);
    vector<vector<ll>> c(size, vector<ll>(size));
    for (int i=0; i<size; i++) {
        for (int j=0; j<size;j++) {
            for (int k=0; k<size; k++) c[i][j]+=a[i][k]*b[k][j];
            c[i][j]%=mod;
        }
    }
    return c;
}

int main() {
    fastio;
    ll n;
    cin>>n;
    vector<vector<ll>> v={ { 1, 1 }, { 1, 0 } };
    vector<vector<ll>> ans={ { 1, 0 }, { 0, 1 } };
    while (n) {
        if (n%2) ans=f(ans, v);
        v=f(v, v);
        n/=2;
    }
    cout<<ans[0][1];
}
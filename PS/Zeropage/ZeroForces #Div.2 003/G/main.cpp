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

int main() {
    fastio;
    ll n;
    cin>>n;
    for (ll i=1; i; i++) {
        ll tmp=i;
        ll tmpj=1;
        for (int j=0; j<=i; j++) {
            tmp+=(i+1)*tmpj;
            tmpj*=2;
        }
        if (tmp>=n) {
            cout<<i;
            return 0;
        }
    }
}
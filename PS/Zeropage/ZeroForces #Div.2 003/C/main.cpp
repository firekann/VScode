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

int f(int l, int r) {
    int tmp=1;
    for (int i=l; i<=r; i++) tmp*=v[i];
    return tmp;
}

int main() {
    fastio;
    int n;
    cin>>n;
    v.resize(n+1);
    for (int i=1; i<=n; i++) cin>>v[i];
    int ans=0;
    for (int i=1; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            for (int k=j+1; k<n; k++) {
                ans=max(ans, f(1, i)+f(i+1, j)+f(j+1, k)+f(k+1, n));
            }
        }
    }
    cout<<ans;
}
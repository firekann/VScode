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

void f(vector<vector<int>> &v, int x, int y, int n, int t) {
    if (n==1) return;
    double cnt1, cnt0, cnt;
    cnt1=cnt0=cnt=0;
    for (int i=x; i<x+n; i++) {
        for (int j=y; j<y+n; j++) {
            if (v[i][j]) cnt1++;
            else cnt0++;
            cnt++;
        }
    }
    if ((cnt1/cnt)*100>=t) for (int i=x; i<x+n; i++) for (int j=y; j<y+n; j++) v[i][j]=1;
    else if ((cnt0/cnt)*100>=t) for (int i=x; i<x+n; i++) for (int j=y; j<y+n; j++) v[i][j]=0;
    else {
        int nn=n/2;
        f(v, x, y, nn, t);
        f(v, x, y+nn, nn, t);
        f(v, x+nn, y, nn, t);
        f(v, x+nn, y+nn, nn, t);
    }
    return;
}

int main() {
    fastio;
    for (int T=1; 1; T++) {
        int n, t;
        cin>>n;
        if (!n) return 0;
        cin>>t;
        vector<vector<int>> vv(n);
        for (auto &i:vv) {
            string s;
            cin>>s;
            for (auto j:s) i.pb(j-'0');
        }
        f(vv, 0, 0, n, t);
        cout<<"Image "<<T<<":\n";
        for (auto i:vv) {
            for (auto j:i) cout<<j;
            cout<<"\n";
        }
    }
}
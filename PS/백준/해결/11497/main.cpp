#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr)
#define X first
#define Y second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mid ((l + r) >> 1)

using namespace std;
typedef long long ll;
const int dx[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

int main()
{
    fastio;
    int T;
    cin >> T;
    for (; T--;) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto& i : v)
            cin >> i;
        sort(all(v));
        int ans = -1;
        for (int i = 2; i < n; i += 2) {
            ans = max(ans, v[i] - v[i - 2]);
        }
        for (int i = 3; i < n; i += 2) {
            ans = max(ans, v[i] - v[i - 2]);
        }
        ans = max({ ans, v[1] - v[0], v[n - 1] - v[n - 2] });
        cout << ans << "\n";
    }
}
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
    for (int n, m; ~scanf("%d %d", &n, &m);) {
        vector<vector<int>> v(n, vector<int>(n));
        for (auto& i : v)
            for (auto& j : i)
                cin >> j;
        pair<int, int> pos = { 0, 0 };
        map<int, bool> ans_mp;
        int ans = 1e9;
        for (int i = 0; i <= n - m; i++) {
            for (int j = 0; j <= n - m; j++) {
                map<int, bool> mp;
                for (int ii = i; ii < i + m; ii++) {
                    for (int jj = j; jj < j + m; jj++) {
                        mp[v[ii][jj]] = true;
                    }
                }
                if (sz(mp) < ans) {
                    pos = { i + 1, j + 1 };
                    ans = sz(mp);
                }
            }
        }
        cout << pos.X << " " << pos.Y << "\n";
    }
}
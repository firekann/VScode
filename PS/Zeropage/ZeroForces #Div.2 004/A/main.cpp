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
    int n, l;
    cin >> n >> l;
    vector<int> v(n);
    for (auto& i : v)
        cin >> i;
    sort(all(v));
    int s = v[0], ans = 0;
    for (int i = 1; i < n; i++) {
        if (v[i] - s + 1 > l) {
            ans++;
            s = v[i];
        }
    }
    if (s != v[0])
        ans++;
    if (s == v[0])
        ans = 1;
    cout << ans;
}
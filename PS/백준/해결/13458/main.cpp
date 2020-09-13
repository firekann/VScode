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
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& i : v)
        cin >> i;
    int a, b;
    cin >> a >> b;
    ll ans = 0;
    for (auto i : v) {
        int tmp = i - a;
        ans++;
        if (tmp > 0)
            ans += (tmp / b) + (tmp % b == 0 ? 0 : 1);
    }
    cout << ans;
}
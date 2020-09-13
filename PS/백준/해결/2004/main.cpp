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

ll cnt(ll n, ll num)
{
    ll ans = 0;
    for (ll i = num; n / i >= 1; i *= num)
        ans += n / i;
    return ans;
}

int main()
{
    fastio;
    ll n, r;
    cin >> n >> r;
    ll o, e;
    o = e = 0;
    o += cnt(n, 5);
    if (r != 0)
        o -= cnt(r, 5);
    if (n != r)
        o -= cnt(n - r, 5);
    e += cnt(n, 2);
    if (r != 0)
        e -= cnt(r, 2);
    if (n != r)
        e -= cnt(n - r, 2);
    cout << min(o, e);
}
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

bool cmp(const pair<pii, pii> a, const pair<pii, pii> b)
{
    if (a.Y.X == b.Y.X)
        return a.Y.Y < b.Y.Y;
    return a.Y.X < b.Y.X;
}

int main()
{
    fastio;
    int n;
    cin >> n;
    int scr, k;
    cin >> scr >> k;
    vector<pair<pii, pii>> v(n);
    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        v[i - 1] = { { tmp, i }, { abs(scr - tmp), scr - tmp > 0 ? -1 : 1 } };
    }
    sort(all(v), cmp);
    for (int i = 0; i < k; i++)
        cout << v[i].X.Y << " ";
}
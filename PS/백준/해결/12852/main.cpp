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

vector<pii> dp(1000001, { 1e9, 0 });

int main()
{
    fastio;
    int n;
    cin >> n;
    dp[1] = { 0, 0 };
    for (int i = 1; i < n; i++) {
        if (i * 3 <= n && dp[i * 3].X > dp[i].X + 1)
            dp[i * 3] = { dp[i].X + 1, i };
        if (i * 2 <= n && dp[i * 2].X > dp[i].X + 1)
            dp[i * 2] = { dp[i].X + 1, i };
        if (dp[i + 1].X > dp[i].X + 1)
            dp[i + 1] = { dp[i].X + 1, i };
    }
    int pre = dp[n].Y;
    cout << dp[n].X << "\n";
    cout << n << " ";
    for (int i = 0; i < dp[n].X; i++) {
        cout << pre << " ";
        pre = dp[pre].Y;
    }
}
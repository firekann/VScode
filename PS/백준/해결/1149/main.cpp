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
#define INPUT_FILE "input.txt"
#define OUTPUT_FILE "output.txt"
//ifstream input(INPUT_FILE);
//ofstream output(OUTPUT_FILE);

using namespace std;
typedef long long ll;
const int dx[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

vector<vector<int>> dp(2, vector<int>(3));

int main()
{
    fastio;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> dp[~i & 1][j];
            dp[~i & 1][j] += min(dp[i & 1][j ? 0 : 1], dp[i & 1][j == 2 ? 1 : 2]);
        }
    }
    sort(all(dp[n & 1]));
    cout << dp[n & 1][0];
}
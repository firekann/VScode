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

int N, M;

void ck(vector<vector<int>>& v, int n, int m)
{
    if (v[n][m] == 0)
        return;
    v[n][m] = 0;
    for (int i = 0; i < 4; i++) {
        int nn = n + dx[i], mm = m + dy[i];
        if (nn >= 0 && nn < N && mm >= 0 && mm < M) {
            ck(v, nn, mm);
        }
    }
}

int solution(vector<vector<int>> v)
{
    N = sz(v), M = sz(v[0]);
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (v[i][j] == 1) {
                ans++;
                ck(v, i, j);
            }
        }
    }
    return ans;
}

int main()
{
    fastio;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (auto& i : v)
        for (auto& j : i)
            cin >> j;
    cout << solution(v);
}
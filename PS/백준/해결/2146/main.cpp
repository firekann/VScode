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

int n;
vector<vector<int>> v;
vector<vector<bool>> visit;

void dfs(int x, int y, vector<pair<int, int>>& pos)
{
    if (v[x][y] == 0)
        return;
    v[x][y] = 0;
    pos.pb({ x, y });
    for (int i = 0; i < 4; i++) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (tx >= 0 && tx < n && ty >= 0 && ty < n)
            dfs(tx, ty, pos);
    }
    return;
}

int bfs(int X, int Y)
{
    int res = 0;
    queue<pair<int, int>> q;
    q.push({ X, Y });
    vector<vector<bool>> visit(n, vector<bool>(n, false));
    while (!q.empty()) {
        pair<int, int> qt = q.front();
        q.pop();
        int x = qt.X, y = qt.Y;
        bool flag = false;
        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (tx >= 0 && tx < n && ty >= 0 && ty < n) {
                if (!visit[tx][ty]) {
                    q.push({ tx, ty });
                    visit[tx][ty] = true;
                }
                if (v[tx][ty] == 1) {
                    flag = true;
                    res = abs(X - tx) + abs(Y - ty) - 1;
                }
            }
        }
        if (flag)
            break;
    }
    return res ? res : 1e9;
}

int main()
{
    fastio;
    cin >> n;
    v.resize(n, vector<int>(n));
    visit.resize(n, vector<bool>(n, false));
    for (auto& i : v)
        for (auto& j : i)
            cin >> j;
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j] == 0)
                continue;
            vector<pair<int, int>> pos;
            dfs(i, j, pos);
            for (auto itr : pos) {
                ans = min(ans, bfs(itr.X, itr.Y));
            }
        }
    }
    cout << ans;
}
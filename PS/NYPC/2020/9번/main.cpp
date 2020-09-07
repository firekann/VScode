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
vector<vector<bool>> visit;
vector<vector<char>> vv;
vector<vector<string>> way;

void bfs()
{
    queue<pair<pii, pair<int, string>>> q;
    int cnt = 0;
    int start, end;
    for (int i = 0; i < n; i++) {
        if (vv[0][i] == 'U') {
            end = i;
            break;
        }
        if (vv[0][i] == 'D')
            cnt++;
        visit[0][i] = true;
    }
    string tmps = "";
    for (int i = 0; i < end; i++) {
        if (vv[1][i] != 'U') {
            q.push({ { 1, i }, { cnt, tmps + "D" } });
            way[0][i] = tmps;
        }
        tmps += "R";
    }
    while (!q.empty()) {
        pair<pii, pair<int, string>> node = q.front();
        q.pop();
        if (visit[node.X.X][node.X.Y])
            continue;
        cout << node.X.X << " " << node.X.Y << " " << node.Y.X << " " << node.Y.Y << "\n";
        cnt = 0;
        tmps = "";
        for (int i = node.X.Y; i >= 0; i--) {
            if (vv[node.X.X][i] == 'U') {
                start = i + 1;
                tmps += "L";
                break;
            }
        }
        if (sz(tmps)) {
            tmps.substr(0, sz(tmps) - 1);
        }
        for (int i = start; i < n; i++) {
            if (vv[node.X.X][i] == 'U') {
                end = i;
                break;
            }
            if (vv[node.X.X][i] == 'D')
                cnt++;
            visit[node.X.X][i] = true;
        }
        for (int i = 0; i < end; i++) {
            if (vv[node.X.X + 1][i] != 'U') {
                q.push({ { node.X.X + 1, i }, { cnt, node.Y.Y + tmps + "D" } });
                way[node.X.X + 1][i] = node.Y.Y + tmps;
            }
            tmps += "R";
        }
    }
}

int main()
{
    fastio;
    cin >> n;
    visit.resize(n, vector<bool>(n, false));
    vv.resize(n, vector<char>(n));
    way.resize(n + 1, vector<string>(n + 1, ""));
    for (auto& i : vv)
        for (auto& j : i)
            cin >> j;
    bfs();
    cout << "\nend\n";
}
#include <bits/stdc++.h>

using namespace std;

const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { -1, 0, 1, 0 };

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> vv(n, vector<int>(m));
    for (auto& i : vv) {
        for (auto& j : i) {
            cin >> j;
        }
    }
    if (vv[0][0] == -1) {
        cout << "-1";
        return 0;
    }
    int ans = -1;
    priority_queue<piii, vector<piii>, greater<piii>> pq;
    pq.push({ vv[0][0], { 0, 0 } });
    vector<vector<bool>> visit(n, vector<bool>(m, false));
    while (!pq.empty()) {
        auto piii = pq.top();
        pq.pop();
        if (piii.second.first == n - 1 && piii.second.second == m - 1) {
            ans = piii.first;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int tx = piii.second.first + dx[i];
            int ty = piii.second.second + dy[i];
            if (tx < 0 || ty < 0 || tx >= n || ty >= m)
                continue;
            if (visit[tx][ty] || vv[tx][ty] == -1)
                continue;
            pq.push({ piii.first + vv[tx][ty], { tx, ty } });
            visit[tx][ty] = true;
        }
    }
    cout << ans;
}
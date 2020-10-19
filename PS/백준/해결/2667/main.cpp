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
    vector<vector<int>> vv(n);
    for (auto& i : vv) {
        string s;
        cin >> s;
        for (auto j : s) {
            i.pb(j - '0');
        }
    }
    vector<int> ans;
    for (int I = 0; I < n; I++) {
        for (int J = 0; J < n; J++) {
            if (vv[I][J] != 1)
                continue;
            int cnt = 0;
            queue<pair<int, int>> q;
            q.push({ I, J });
            while (!q.empty()) {
                int x = q.front().X;
                int y = q.front().Y;
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                        continue;
                    if (vv[nx][ny] == 1) {
                        vv[nx][ny] = 0;
                        cnt++;
                        q.push({ nx, ny });
                    }
                }
            }
            cnt = cnt == 0 ? 1 : cnt;
            ans.pb(cnt);
        }
    }
    sort(all(ans));
    cout << sz(ans) << "\n";
    for (auto i : ans) {
        cout << i << "\n";
    }
}
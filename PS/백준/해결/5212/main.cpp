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
    int n, m;
    cin >> n >> m;
    vector<string> vv(n);
    for (auto& i : vv)
        cin >> i;
    vector<string> v = vv;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vv[i][j] == '.')
                continue;
            int cnt = 0;
            for (int q = 0; q < 4; q++) {
                int x = i + dx[q];
                int y = j + dy[q];
                if (x < 0 || x >= n || y < 0 || y >= m) {
                    cnt++;
                    continue;
                }
                if (vv[x][y] == '.')
                    cnt++;
            }
            if (cnt > 2) {
                v[i][j] = '.';
            }
        }
    }
    int startj, endj;
    for (int i = 0; i < m; i++) {
        bool flag = false;
        for (int j = 0; j < n; j++) {
            if (v[j][i] == 'X') {
                startj = i;
                flag = true;
                break;
            }
        }
        if (flag)
            break;
    }
    for (int i = m - 1; i >= 0; i--) {
        bool flag = false;
        for (int j = 0; j < n; j++) {
            if (v[j][i] == 'X') {
                endj = i;
                flag = true;
                break;
            }
        }
        if (flag)
            break;
    }
    int endi;
    for (int i = n - 1; i >= 0; i--) {
        bool flag = false;
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 'X') {
                endi = i;
                flag = true;
                break;
            }
        }
        if (flag)
            break;
    }
    bool flag = false;
    for (int i = 0; i <= endi; i++) {
        if (!flag) {
            for (int j = startj; j <= endj; j++) {
                if (v[i][j] == 'X') {
                    flag = true;
                    break;
                }
            }
        }
        if (flag) {
            for (int j = startj; j <= endj; j++)
                cout << v[i][j];
            cout << "\n";
        }
    }
}
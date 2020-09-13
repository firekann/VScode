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

vector<vector<int>> edge;
vector<bool> visit;
vector<bool> visit2;

int main()
{
    fastio;
    int n, m, q;
    cin >> n >> m >> q;
    edge.resize(n + 1);
    visit.resize(n + 1, false);
    visit2.resize(n + 1, false);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edge[a].pb(b);
        edge[b].pb(a);
    }
    for (; q--;) {
        int tmp;
        cin >> tmp;
        int cnt = 0;
        if (visit2[tmp]) {
            cout << "0\n";
            continue;
        }
        if (!visit[tmp])
            cnt++;
        visit[tmp] = true;
        visit2[tmp] = true;
        for (auto i : edge[tmp]) {
            if (!visit[i])
                cnt++;
            visit[i] = true;
        }
        cout << cnt << "\n";
    }
}
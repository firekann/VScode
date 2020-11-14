#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr)
#define X first
#define Y second
#define pb push_back
#define sz(x) (injt) x.size()
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
    int n, k;
    cin >> n >> k;
    vector<vector<pii>> graph(n + 1);
    vector<bool> check(n + 1, false);
    for (int i = 1; i < n; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        graph[x].push_back({ w, y });
        graph[y].push_back({ w, x });
    }

    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        check[x] = true;
        sort(graph[x].begin(), graph[x].end());
        check[graph[x][0].second] = true;
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (check[i]) {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
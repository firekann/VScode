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
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int Answer, cnt;

void dfs(vector<vector<pii>> &edge, int start, int end, int pre, int cut)
{
    bool ck = true;
    int tmp = cut;
    for (auto i : edge[start])
    {
        if (i.Y > pre)
        {
            dfs(edge, i.X, end, i.Y, tmp);
            tmp++;
            ck = false;
        }
    }
    if (ck)
    {
        if (start == end)
        {
            if (cnt == -1)
                cnt = cut;
            else
                cnt = min(cnt, cut);
        }
        return;
    }
    if (start == end)
    {
        for (auto i : edge[start])
        {
            if (i.Y > pre)
            {
                cut++;
            }
        }
        if (cnt == -1)
            cnt = cut;
        else
            cnt = min(cnt, cut);
    }
    return;
}

int main()
{
    fastio;
    int T, test_case;
    cin >> T;
    for (test_case = 0; test_case < T; test_case++)
    {
        Answer = 0;
        int n, k, m;
        cin >> n >> k >> m;
        vector<vector<pii>> edge(n + 1);
        for (int i = 0; i < k; i++)
        {
            int a, b;
            cin >> a >> b;
            edge[a].pb({b, i});
            edge[b].pb({a, i});
        }
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cnt = -1;
            cin >> a >> b;
            dfs(edge, a, b, -1, 0);
            ans += cnt;
        }
        Answer = ans;
        cout << "Case #" << test_case + 1 << endl;
        cout << Answer << endl;
    }

    return 0;
}
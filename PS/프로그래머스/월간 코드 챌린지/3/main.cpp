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

vector<map<int, int>> vvm;
vector<vector<int>> vv;

void f(int s, int e)
{
}

int solution(int n, vector<vector<int>> edges)
{
    int answer = 0;
    vv.resize(n + 1);
    vvm.resize(n + 1);
    for (auto i : edges) {
        vvm[i[0]][i[1]] = -1;
        vvm[i[1]][i[0]] = -1;
        vv[i[0]].pb(i[1]);
        vv[i[1]].pb(i[0]);
    }
    for (int i = 1; i <= n; i++) {
        queue<pair<int, int>> q;
        vector<bool> visit(n + 1, false);
        q.push({ i, 1 });
        while (!q.empty()) {
            int tmp = q.front().first;
            int dist = q.front().second;
            q.pop();
            if (visit[tmp])
                continue;
            visit[tmp] = true;
            for (auto itr : vv[tmp]) {
                if (visit[itr])
                    continue;
                vvm[i][itr] = dist;
                //cout << i << " " << tmp << " " << itr << " " << dist << "\n";
                q.push({ itr, dist + 1 });
            }
        }
    }
    //cout << "================\n";
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            for (int q = j + 1; q <= n; q++) {
                vector<int> tmpv;
                tmpv.pb(vvm[i][j]);
                tmpv.pb(vvm[i][q]);
                tmpv.pb(vvm[j][q]);
                sort(all(tmpv));
                //cout << i << " " << j << " " << q << " " << tmpv[1] << "\n";
                answer = max(answer, tmpv[1]);
            }
        }
    }
    return answer;
}

int main()
{
    fastio;
    int n;
    cin >> n;
    vector<vector<int>> arr(n - 1);
    for (auto& i : arr) {
        int a, b;
        cin >> a >> b;
        i.pb(a);
        i.pb(b);
    }
    cout << solution(n, arr);
}
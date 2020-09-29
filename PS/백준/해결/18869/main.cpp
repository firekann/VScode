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

int main()
{
    fastio;
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        vector<pair<int, int>> tmp;
        for (int j = 0; j < m; j++)
        {
            int t;
            cin >> t;
            //정렬할때 같은 값의 경우 뒤의 j를 보고 정렬하므로 대추주 당한 상황을 -만 붙이면 해결할 수 있다.
            tmp.push_back({t, -j});
        }
        sort(all(tmp));
        for (auto itr : tmp)
            v[i] += to_string(itr.Y) + "/";
    }
    sort(all(v));
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (v[i] == v[j])
                cnt++;
        }
    }
    cout << cnt;
}
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
    int n, k;
    cin >> n >> k;
    vector<int> v(k);
    for (auto& i : v)
        cin >> i;
    int cnt = 1;
    vector<bool> mp(1010, false);
    mp[v[0]] = true;
    vector<int> ans;
    ans.pb(v[0]);
    for (int i = 1; i < k; i++) {
        if (v[i] == v[i - 1]) {
            if (!mp[v[i]]) {
                mp[v[i]] = true;
                ans.pb(v[i]);
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
    for (auto i : ans)
        cout << i << " ";
}
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

vector<pair<int, int>> solution(vector<pair<int, int>> v)
{
    sort(all(v));
    vector<pair<int, int>> ans;
    int s, e;
    s = e = -1;
    for (auto i : v) {
        if (s <= i.X && i.X <= e) {
            if (s == -1)
                s = i.X;
            e = max(e, i.Y);
        } else {
            if (s != -1)
                ans.pb({ s, e });
            s = i.X;
            e = i.Y;
        }
    }
    ans.pb({ s, e });
    return ans;
}

int main()
{
    fastio;
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (auto& i : v)
        cin >> i.X >> i.Y;
    cout << "[";
    for (auto i : solution(v)) {
        cout << "[" << i.X << ", " << i.Y << "], ";
    }
    cout << "]";
}
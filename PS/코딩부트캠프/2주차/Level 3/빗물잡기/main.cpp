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

int solution(vector<int> v)
{
    int ans = 0;
    stack<int> s;
    int maxv = -1;
    for (auto i : v) {
        maxv = max(maxv, i);
        s.push(maxv - i);
    }
    reverse(all(v));
    maxv = -1;
    for (auto i : v) {
        maxv = max(maxv, i);
        ans += min(maxv - i, s.top());
        s.pop();
    }
    return ans;
}

int main()
{
    fastio;
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& i : v)
        cin >> i;
    cout << solution(v);
}
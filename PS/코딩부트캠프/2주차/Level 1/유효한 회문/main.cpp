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

string s;

bool solve(int l, int r, bool ck)
{
    if (l > r)
        return true;
    if (s[l] == s[r])
        return solve(l + 1, r - 1, ck);
    else if (ck)
        return max(solve(l + 1, r, false), solve(l, r - 1, false));
    else
        return false;
}

bool solution(string ss)
{
    s = ss;
    int l = 0, r = sz(s) - 1;
    return solve(l, r, true);
}

int main()
{
    fastio;
    string s;
    cin >> s;
    cout << (solution(s) ? "True" : "False");
}
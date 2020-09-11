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

bool solution(string s)
{
    int l = 0, r = sz(s) - 1;
    bool ck = false, flag = true;
    while (l < r) {
        if (s[l] == s[r]) {
            l++, r--;
            continue;
        } else {
            if (r - l < 2) {
                break;
            } else if (ck) {
                flag = false;
                break;
            } else if (s[l] == s[r - 1] && (l + 1 <= r - 2) ? true : (s[l + 1] == s[r - 2])) {
                ck = true;
                l++;
                r -= 2;
                continue;
            } else if (s[l + 1] == s[r] && (l + 2 <= r - 1) ? true : (s[l + 2] == s[r - 1])) {
                ck = true;
                l += 2;
                r--;
                continue;
            } else {
                flag = false;
                break;
            }
        }
    }
    if (flag)
        return true;
    else
        return false;
}

int main()
{
    fastio;
    string s;
    cin >> s;
    cout << (solution(s) ? "True" : "False");
}
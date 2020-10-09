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

vector<string> split(string s, string k)
{
    vector<string> rec;
    string ts = "";
    for (auto itr : s) {
        bool flag = false;
        for (auto i : k) {
            if (i == itr) {
                flag = true;
                break;
            }
        }
        if (flag) {
            if (sz(ts)) {
                rec.pb(ts);
            }
            ts = "";
        } else {
            ts += itr;
        }
    }
    if (sz(ts)) {
        rec.pb(ts);
    }
    return rec;
}

int main()
{
    fastio;
    vector<string> key;
    key.pb("c");
    key.pb("j");
    key.pb("n");
    key.pb("m");
    key.pb("t");
    key.pb("s");
    key.pb("l");
    key.pb("d");
    key.pb("qu");
    string s;
    getline(cin, s);
    vector<string> vs = split(s, " -");
    int ans = sz(vs);
    for (auto i : vs) {
        vector<string> tmp = split(i, "'");
        int tmpsz = sz(tmp);
        if (tmpsz == 1)
            continue;
        for (auto itr : key) {
            if (tmp[0] == itr) {
                if (tmp[1][0] == 'a' || tmp[1][0] == 'e' || tmp[1][0] == 'i' || tmp[1][0] == 'o' || tmp[1][0] == 'u' || tmp[1][0] == 'h') {
                    ans++;
                }
                break;
            }
        }
    }
    cout << ans;
}
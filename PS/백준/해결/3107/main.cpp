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

vector<string>
split(string s, char k)
{
    vector<string> rec;
    string ts = "~";
    for (auto itr : s) {
        if (itr == k) {
            if (sz(ts) == 0)
                ts = "~~~~";
            if (ts != "~")
                rec.pb(ts);
            ts = "";
        } else {
            if (ts == "~")
                ts = "";
            ts += itr;
        }
    }
    if (sz(ts))
        rec.pb(ts);
    return rec;
}

int main()
{
    fastio;
    string s;
    cin >> s;
    vector<string> word = split(s, ':');
    for (auto& itr : word) {
        if (itr == "~~~~") {
            int tmp = sz(word);
            itr = "0000";
            for (int i = 0; i < 8 - tmp; i++) {
                itr = "0000:" + itr;
            }
        } else {
            int tmp = sz(itr);
            for (int i = 0; i < 4 - tmp; i++) {
                itr = "0" + itr;
            }
        }
    }
    for (int i = 0; i < sz(word); i++) {
        cout << word[i];
        if (i != sz(word) - 1)
            cout << ":";
    }
}
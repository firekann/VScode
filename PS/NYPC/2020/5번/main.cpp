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

vector<string> split(string s, char k)
{
    vector<string> rec;
    string ts;
    for (auto itr : s) {
        if (itr == k) {
            rec.pb(ts);
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
    vector<int> v(3);
    for (int i = 0; i < 3; i++) {
        string tmps;
        cin >> tmps;
        vector<string> sv;
        sv = split(tmps, ':');
        v[i] = stoi(sv[0] + sv[1] + sv[2]);
    }
    int n;
    cin >> n;
    for (; n--;) {
        string tmps;
        cin >> tmps;
        vector<string> sv = split(tmps, ':');
        int num = stoi(sv[0] + sv[1] + sv[2]);
        if (num <= v[2])
            cout << "***\n";
        else if (num <= v[1])
            cout << "**\n";
        else if (num <= v[0])
            cout << "*\n";
        else
            cout << ":(\n";
    }
}
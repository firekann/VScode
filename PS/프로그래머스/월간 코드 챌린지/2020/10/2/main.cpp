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

vector<vector<int>> vv;
string ans;

void f(int x, int y, int n)
{
    if (n == 1) {
        ans += to_string(vv[x][y]);
        return;
    }
    bool a, b;
    a = b = true;
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (vv[i][j])
                a = false;
            else
                b = false;
        }
    }
    if (a)
        ans += "0";
    else if (b)
        ans += "1";
    else {
        int nn = n / 2;
        f(x, y, nn);
        f(x, y + nn, nn);
        f(x + nn, y, nn);
        f(x + nn, y + nn, nn);
    }
    return;
}

vector<int> solution(vector<vector<int>> arr)
{
    vector<int> answer;
    vv = arr;
    f(0, 0, sz(arr));
    int odd, even;
    odd = even = 0;
    for (auto i : ans) {
        if (i == '0')
            even++;
        else
            odd++;
    }
    answer.pb(even);
    answer.pb(odd);
    return answer;
}

int main()
{
    fastio;
    int n;
    cin >> n;
    vv.resize(n);
    for (auto& i : vv) {
        string tmps;
        cin >> tmps;
        for (auto j : tmps)
            i.pb(j - '0');
    }
    solution(vv);
}
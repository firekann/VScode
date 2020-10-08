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

int solution(int n)
{
    int answer = 0;
    if (!n)
        return 0;
    string s;
    while (n > 0) {
        s.pb((n % 3) + '0');
        n /= 3;
    }
    ll tmpll = stoll(s);
    s = to_string(tmpll);
    int len = sz(s) - 1;
    for (auto i : s) {
        answer += (i - '0') * (int)pow(3, len--);
    }
    return answer;
}

int main()
{
    fastio;
    int n;
    cin >> n;
    cout << solution(n);
}
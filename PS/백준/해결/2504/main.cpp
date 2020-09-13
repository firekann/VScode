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
    string s;
    cin >> s;
    stack<char> st;
    ll ans = 0;
    bool flag = false;
    int tmp = 1;
    char prec;
    for (auto i : s) {
        if (i == '(') {
            tmp *= 2;
            st.push(i);
        } else if (i == '[') {
            tmp *= 3;
            st.push(i);
        } else if (i == ')') {
            if (st.empty() || st.top() != '(') {
                flag = true;
                break;
            }
            if (prec == '(')
                ans += tmp;
            st.pop();
            tmp /= 2;
        } else if (i == ']') {
            if (st.empty() || st.top() != '[') {
                flag = true;
                break;
            }
            if (prec == '[')
                ans += tmp;
            st.pop();
            tmp /= 3;
        }
        prec = i;
    }
    if (flag || !st.empty())
        cout << "0";
    else
        cout << ans;
}
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

string solution(string s)
{
    string ans = "";
    stack<string> st;
    int cnt = 0;
    for (auto i : s) {
        if (i == ']') {
            cnt--;
            vector<string> tmpv;
            int n;
            for (; 1;) {
                string sttmp = st.top();
                st.pop();
                if ('0' <= sttmp[0] && sttmp[0] <= '9') {
                    n = stoi(sttmp);
                    break;
                }
                tmpv.pb(sttmp);
            }
            reverse(all(tmpv));
            string tmp = "";
            for (auto itr : tmpv) {
                tmp += itr;
            }
            string tmps = "";
            for (int j = 0; j < n; j++) {
                tmps += tmp;
            }
            if (cnt) {
                st.push(tmps);
            } else {
                ans += tmps;
            }
        } else if (i == '[') {
            cnt++;
        } else if ('0' <= i && i <= '9') {
            st.push(string(1, i));
        } else {
            if (cnt) {
                st.push(string(1, i));
            } else {
                ans += i;
            }
        }
    }
    return ans;
}

int main()
{
    fastio;
    string s;
    cin >> s;
    cout << solution(s);
}
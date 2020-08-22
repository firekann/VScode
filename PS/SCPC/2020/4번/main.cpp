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
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int Answer;

int main()
{
    fastio;
    int T, test_case;

    cin >> T;
    for (test_case = 0; test_case < T; test_case++)
    {
        Answer = 0;
        int n, k, m;
        string S;
        cin >> n >> k >> m;
        cin >> S;
        for (int j = 0; j <= n; j++)
        {
            string s = S;
            if (j && s[j - 1] == '1')
                continue;
            if (j)
                s[j - 1] = '1';
            int minv = 1e9, maxv = 0;
            map<int, int> mp;
            for (int i = 0; i <= n - k; i++)
            {
                int tmp;
                sscanf(s.substr(i, k).c_str(), "%d", &tmp);
                if (mp[tmp])
                    mp[tmp]++;
                else
                    mp[tmp] = 1;
                minv = min(minv, tmp);
                maxv = max(maxv, tmp);
            }
            if (maxv <= m)
                m = maxv;
            int ans = 0, cnt = 0;
            for (int i = minv; i <= minv + m; i++)
            {
                cnt += mp[i];
            }
            ans = cnt;
            for (int i = minv + 1; i <= maxv - m; i++)
            {
                cnt -= mp[i - 1];
                cnt += mp[i + m];
                ans = max(ans, cnt);
            }
            Answer = max(Answer, ans);
        }
        cout << "Case #" << test_case + 1 << endl;
        cout << Answer << endl;
    }

    return 0; //Your program should return 0 on normal termination.
}
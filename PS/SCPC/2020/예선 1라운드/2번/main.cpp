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

int win, lose, n, k;

void dfs(stack<int> a, stack<int> b)
{
    if ((sz(a) == 1 && sz(b) == 0) || (sz(a) == 0 && sz(b) == 1))
    {
        win++;
        return;
    }
    int sum;
    stack<int> aa = a;
    stack<int> bb = b;
    int tmp;
    for (sum = 0; !a.empty();)
    {
        tmp = a.top();
        a.pop();
        sum += tmp;
    }
    int len = sz(b);
    if ((len == 1 && sum <= k) || (len == 0 && sum - tmp <= k))
        win++;
    for (sum = 0; !b.empty();)
    {
        tmp = b.top();
        b.pop();
        sum += tmp;
    }
    a = aa;
    int len = sz(a);
    if ((len == 1 && sum <= k) || (len == 0 && sum - tmp <= k))
        win++;

    for (a = aa, sum = 0; !a.empty();)
    {
        sum += a.top();
        a.pop();
        if (sum > k)
            break;
        dfs(a, b);
    }
    for (b = bb, sum = 0; !b.empty();)
    {
        sum += b.top();
        b.pop();
        if (sum > k)
            break;
        dfs(aa, b);
    }
    return;
}

int main()
{
    fastio;
    int T, test_case;
    cin >> T;
    for (test_case = 0; test_case < T; test_case++)
    {
        Answer = 0;
        win = lose = 0;
        cin >> n >> k;
        stack<int> a, b;
        for (int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            a.push(tmp);
        }
        for (int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            b.push(tmp);
        }
        dfs(a, b);
        cout << "Case #" << test_case + 1 << "\n";
        cout << win << " " << lose << "\n";
    }

    return 0;
}
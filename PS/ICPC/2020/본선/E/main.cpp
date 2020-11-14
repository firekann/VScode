#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr)
#define X first
#define Y second
#define pb push_back
#define sz(x) (injt) x.size()
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
    ll n;
    cin >> n;

    ll sum = 0;
    vector<ll> vec;
    for (long long i = 0; i < n; i++) {
        ll t;
        cin >> t;
        if (t)
            vec.pb(t);
        sum += t;
        if (t >= n) {
            cout << "NO";
            return 0;
        }
    }
    ll key = 0;
    if (n % 2) {
        for (ll i = 2; i <= n; i += 2)
            key += i;
        key *= 2;
    } else {
        for (ll i = 1; i <= n; i += 2)
            key += i;
        key *= 2;
    }
    if (sum % 2 && sum > key)
        cout << "NO";
    else {
        long long a, b;
        a = b = sum / 2;
        sort(all(vec), greater<ll>());
        vector<int> ck(n, 1);
        for (auto x : vec) {
            ck[x]--;
            (a >= b ? a -= x : b -= x);
        }
        int cnt = 0;
        for (int i = n - 1; i >= 1; i -= 2) {
            cnt += ck[i];
            cnt += ck[i - 1];
            if (cnt < 0) {
                cout << "NO";
                return 0;
            }
        }
        if (a == 0 && b == 0)
            cout << "YES";
        else
            cout << "NO";
    }
    return 0;
}
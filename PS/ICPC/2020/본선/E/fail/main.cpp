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
    vector<ll> v;
    for (ll i = 0; i < n; i++) {
        ll tmp;
        cin >> tmp;
        sum += tmp;
        if (tmp) {
            v.pb(tmp);
        }
        if (tmp >= n) {
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
    if (sum % 2 || sum > key) {
        cout << "NO";
    } else {
        ll a, b;
        a = b = sum / 2;
        sort(all(v), greater<ll>());
        for (auto i : v) {
            if (a >= b) {
                a -= i;
            } else {
                b -= i;
            }
        }
        if (a == 0 && b == 0)
            cout << "YES";
        else
            cout << "NO";
    }
}
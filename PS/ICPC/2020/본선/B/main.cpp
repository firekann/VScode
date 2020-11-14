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

int my_gcd(int a, int b)
{
    if (a % b == 0)
        return b;
    if (a < b)
        return my_gcd(b, a);
    return my_gcd(b, a % b);
}

int main()
{
    fastio;
    int a[6], b[6];
    for (int i = 0; i < 6; i++)
        cin >> a[i];
    for (int i = 0; i < 6; i++)
        cin >> b[i];

    int cnt = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (a[i] > b[j])
                cnt++;
        }
    }

    int g = my_gcd(cnt, 36);
    cout << cnt / g << '/' << 36 / g;
}
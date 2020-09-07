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
    int T;
    cin >> T;
    for (; T--;) {
        vector<int> a(4), b(4);
        int suma = 0, sumb = 0;
        for (auto& i : a) {
            cin >> i;
            suma += i;
        }
        for (auto& i : b) {
            cin >> i;
            sumb += i;
        }
        sort(all(a), greater<int>());
        sort(all(b), greater<int>());
        if (a[0] <= b[0] && suma > sumb)
            cout << "S\n";
        else if (a[0] > b[0] && suma <= sumb)
            cout << "I\n";
        else
            cout << "R\n";
    }
}
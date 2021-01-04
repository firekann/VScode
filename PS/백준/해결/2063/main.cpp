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
#define INPUT_FILE "input.txt"
#define OUTPUT_FILE "output.txt"
//ifstream input(INPUT_FILE);
//ofstream output(OUTPUT_FILE);

using namespace std;
typedef long long ll;
const int dx[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

int main()
{
    fastio;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<double> v(n);
        for (auto& i : v) {
            cin >> i;
            i *= 2;
        }
        if (n == 1) {
            cout << "NO\n";
            continue;
        }
        sort(all(v));
        double sum = v[0];
        bool flag = true;
        for (int i = 1; i < n; i++) {
            if (v[i] - sum <= 0) {
                cout << "YES\n";
                flag = false;
                break;
            }
            sum += v[i];
        }
        if (flag) {
            cout << "NO\n";
        }
    }
}
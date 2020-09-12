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

double solution(vector<int> vn, vector<int> vm)
{
    double ans = 0.0;
    int n = sz(vn), m = sz(vm);
    if (n && !m) {
        if (n % 2)
            ans = vn[n / 2];
        else
            ans = double(vn[n / 2] + vn[n / 2 - 1]) / 2;
    } else if (!n && m) {
        if (m % 2)
            ans = vm[m / 2];
        else
            ans = double(vm[m / 2] + vm[m / 2 - 1]) / 2;
    } else {
        vector<int> v;
        if (vn[0] > vm[0]) {
            swap(vn, vm);
            swap(n, m);
        }
        int idx = 0;
        for (auto i : vn) {
            for (int j = idx; j < m; j++) {
                if (vm[j] > i) {
                    idx = j;
                    break;
                }
                v.pb(vm[j]);
                if (j == m - 1)
                    idx = j + 1;
            }
            v.pb(i);
        }
        for (int j = idx; j < m; j++) {
            v.pb(vm[j]);
        }
        int nm = n + m;
        if (nm % 2)
            ans = v[nm / 2];
        else
            ans = double(v[nm / 2] + v[nm / 2 - 1]) / 2;
    }
    return ans;
}

int main()
{
    fastio;
    int n, m;
    cin >> n >> m;
    vector<int> vn(n), vm(m);
    for (auto& i : vn)
        cin >> i;
    for (auto& i : vm)
        cin >> i;
    //정렬된 것임을 보장하기 위해서 솔루션은 O(n+m)임
    sort(all(vn));
    sort(all(vm));
    cout << solution(vn, vm);
}
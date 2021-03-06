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

vector<int> solution(vector<int> v)
{
    int l = 0, r = sz(v) - 1;
    for (; r >= 0 && v[r] == 0; r--)
        ;
    while (l < r) {
        if (v[l] == 0) {
            swap(v[l], v[r]);
            for (r--; r >= 0 && v[r] == 0; r--)
                ;
        }
        l++;
    }
    auto itr = v.begin();
    for (; *itr != 0; itr++)
        ;
    sort(v.begin(), itr);
    return v;
}

int main()
{
    fastio;
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& i : v)
        cin >> i;
    cout << "[";
    for (auto i : solution(v))
        cout << i << ", ";
    cout << "]";
}
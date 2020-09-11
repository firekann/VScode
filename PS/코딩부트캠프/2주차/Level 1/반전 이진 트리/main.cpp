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

// 완전이진트리가 아닌 경우 다시 짜야함
vector<int> solution(vector<int> v)
{
    auto itr = v.begin() + 1;
    int range = 1;
    for (int i = 2; range < sz(v); i *= 2) {
        reverse(itr, itr + i);
        itr += i;
        range += i;
    }
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
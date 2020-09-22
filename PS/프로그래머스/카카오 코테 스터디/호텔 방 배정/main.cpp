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

map<ll, ll> mp;

ll find(ll k)
{
    if (!mp[k])
        return k;
    return mp[k] = find(mp[k]);
}

vector<long long> solution(long long k, vector<long long> room_number)
{
    vector<long long> answer;
    for (auto i : room_number) {
        if (!mp[i]) {
            answer.pb(i);
            mp[i] = find(i + 1);
        } else {
            ll tmp = find(i);
            answer.pb(tmp);
            mp[tmp] = find(tmp + 1);
        }
    }
    return answer;
}

int main()
{
    fastio;
    ll k;
    cin >> k;
    int n;
    cin >> n;
    vector<ll> v(n);
    for (auto& i : v)
        cin >> i;
    for (auto i : solution(k, v))
        cout << i << ", ";
}
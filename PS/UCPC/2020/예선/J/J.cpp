#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;
typedef long long ll;
const int dx[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

int state[100010], endstate[100010], t[100010];
vector<vector<int>> event;

int main(){
    fastio
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0;i < m;++i) {
        int k;
        scanf("%d", &k);
        vector<int> tmp(k);
        for(int j = 0;j < k;++j) scanf("%d", &tmp[j]);
        event.push_back(tmp);
    }
    for(int i = 1;i <= n;++i) scanf("%d", endstate + i);

    for(int i = 1;i <= n;++i)
        state[i] = endstate[i];

    for(int i = m - 1;i >= 0;--i) {
        auto e = event[i];
        int f = 1;
        for(int i : e) if(state[i] == 0) f = 0;
        for(int i : e) state[i] = f;
    }

    for(int i = 1;i <= n;++i) t[i] = state[i];
    for(auto e : event) {
        int f = 0;
        for(int i : e) f |= t[i];
        for(int i : e) t[i] = f;
    }

    bool f = true;
    for(int i = 1;i <= n;++i)
        if(endstate[i] != t[i]) f = false;
    
    if(f) {
        printf("YES\n");
        for(int i = 1;i <= n;++i) printf("%d ", state[i]);
    }
    else printf("NO");

    return 0;
}
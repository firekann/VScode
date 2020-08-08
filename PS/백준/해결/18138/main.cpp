#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
#define X first
#define Y second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mid ((l+r)>>1)

using namespace std;
typedef long long ll;
const int dx[] ={ -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[] ={ 0, 1, 0, -1, 1, 1, -1, -1 };

vector<int> v[1010];
vector<bool> visit(1010);
vector<int> matcha, matchb;

bool dfs(int n) {
    if (visit[n]) return false;
    visit[n]=true;
    for (auto i:v[n]) {
        if (matcha[i]==-1||dfs(matcha[i])) {
            matcha[i]=n;
            matchb[n]=i;
            return true;
        }
    }
    return false;
}

int main() {
    fastio;
    int n, m;
    cin>>n>>m;
    vector<double> a(n);
    vector<double> b(m);
    for (auto &i:a) cin>>i;
    for (auto &i:b) cin>>i;
    int cnt=0;
    for (auto i:b) {
        int tmp=0;
        for (auto j:a) {
            if ((i>=(j*0.5)&&i<=(j*0.75))||(i>=j&&i<=(j*1.25))) v[cnt].pb(tmp);
            tmp++;
        }
        cnt++;
    }
    matcha.resize(1010, -1);
    matchb.resize(1010, -1);
    cnt=0;
    for (int i=0; i<m; i++) {
        for (auto itr:visit) itr=false;
        if (dfs(i)) cnt++;
    }
    cout<<cnt;
}
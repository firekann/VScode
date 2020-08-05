#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
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
const int dx[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

vector<int> v[1010];
vector<bool> visit(1010);
vector<int> match(1010);

bool dfs(int n){
    for(auto i:v[n]){
        if(visit[i]) continue;
        visit[i]=true;
        if(!match[i]||dfs(match[i])){
            match[i]=n;
            return true;
        }
    }
    return false;
}

int main(){
    fastio
    int n, m, k;
    cin>>n>>m>>k;
    for(int i=1; i<=n; i++){
        int tmp;
        cin>>tmp;
        v[i].resize(tmp);
        for(auto &j:v[i]) cin>>j;
    }
    int cnt=0;
    for(int i=0; i<=n; i++){
        for(auto itr:visit) itr=false;
        if(dfs(i)) cnt++;
    }
    for(int i=1; i<=n; i++){
        for(auto itr:visit) itr=false;
        if(dfs(i)){
            cnt++;
            k--;
            if(!k) break;
        }
    }
    cout<<cnt;
}
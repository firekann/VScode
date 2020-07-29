#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define X first
#define Y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;
typedef long long ll;
const int dx[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

vector<vector<int>> vm(10010);
vector<int> vn(1010);

void dfs(int *visit, int key){
    if(visit[key]) return;
    visit[key]=1;
    for(int i=0; i<sz(vm[key]); i++) if(!visit[vm[key][i]]) dfs(visit, vm[key][i]);
}

int main(){
    fastio
    int k, n, m;
    cin>>k>>n>>m;
    for(int i=0; i<k; i++){
        int tmp;
        cin>>tmp;
        vn[tmp]=1;
    }
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        vm[b].push_back(a);
    }
    int ans=0;
    for(int i=1; i<=n; i++){
        int visit[1010];
        for(int j=1; j<=n; j++) visit[j]=0;
        dfs(visit, i);
        bool flag=true;
        for(int i=1; i<=n; i++) if(vn[i]) if(!visit[i]) flag=false;
        if(flag) ans++;
    }
    cout<<ans;
}
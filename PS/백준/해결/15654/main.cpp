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

using namespace std;
typedef long long ll;
const int dx[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

int m;
vector<int> v;
vector<bool> visit;
vector<int> save;

void f(int idx){
    if(idx==m){
        for(int i=0; i<m; i++) cout<<save[i]<<" ";
        cout<<"\n";
        return;
    }
    for(int i=0; i<sz(v); i++){
        if(visit[i]) continue;
        visit[i]=true;
        save[idx]=v[i];
        f(idx+1);
        visit[i]=false;
    }
}

int main(){
    fastio
    int n;
    cin>>n>>m;
    v.resize(n);
    visit.resize(n);
    save.resize(n);
    for(auto &i:v) cin>>i;
    sort(all(v));
    f(0);
}
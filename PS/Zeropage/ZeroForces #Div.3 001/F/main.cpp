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

int n;
ll arr[1000100];
queue<ll> q;
int idx=0;

void solve(){
    while(idx<=n){
        if(q.empty()) return;
        ll qv=q.front();
        q.pop();
        for(int i=0; i<qv%10; i++){
            ll pv=qv*10+i;
            q.push(pv);
            arr[++idx]=pv;
        }
    }
}

int main(){
    fastio
    cin>>n;
    for(int i=1; i<=9; i++){
        q.push(i); arr[++idx]=i;
    }
    solve();
    if(!arr[n]&&n) cout<<"-1";
    else cout<<arr[n];
}
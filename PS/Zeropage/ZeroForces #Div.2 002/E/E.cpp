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

int main(){
    fastio
    int n;
    cin>>n;
    vector<ll> v(n);
    for(auto &i:v) cin>>i;
    sort(all(v));
    map<ll, int> mp;
    for(int i=0; i<sz(v)-1; i++){
        int tmp=v[i+1]-v[i];
        if(mp[tmp]) mp[tmp]++;
        else mp[tmp]=1;
    }
    ll dist=1e18;
    int ans=0;
    for(auto i:mp){
        if(i.X<dist){
            dist=i.X;
            ans=i.Y;
        }
    }
    cout<<dist<<" "<<ans;
}
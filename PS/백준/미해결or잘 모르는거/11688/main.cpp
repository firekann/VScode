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

map<pair<ll, ll>, ll> m;
ll gcd(ll a, ll b){if(!a) return b; return gcd(b%a, a);}
ll lcm(ll a, ll b){
    if(!m.count(make_pair(a, b))) m[make_pair(a, b)]=gcd(a, b);
    return a*b/m[make_pair(a, b)];
}

int main(){
    fastio
    ll a, b, c, l;
    cin>>a>>b>>l;
    ll t=lcm(a, b);
    if(l%t){cout<<"-1"; return 0;}
    for(ll i=1; i<=l; i++){
        if(!(l%i)){
            if(lcm(t, i)==l){
                cout<<i;
                return 0;
            }
        }
    }
    cout<<"-1";
}
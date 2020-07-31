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
#define f(a, b) {max(a.l, a.sum+b.l), max(b.r, b.sum+a.r), max({a.r+b.l, a.lr, b.lr, a.sum+b.sum}), a.sum+b.sum}

using namespace std;
typedef long long ll;
const int dx[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

typedef struct point{
    ll x, y, w;
    bool operator<(const point &p){
        if(x!=p.x) return x<p.x;
        return y<p.y;
    }
}point;

typedef struct node{
    ll l, r, lr, sum;
}node;

vector<node> seg(9000);

void update(int i, int v){
    i|=8192;
    seg[i].l=seg[i].r=seg[i].sum=seg[i].lr+=v;
    while(i>>=1) seg[i]=f(seg[i*2], seg[i*2+1]);
}

int main(){
    fastio
    int n;
    cin>>n;
    vector<point> v(n);
    vector<ll> vx, vy;
    for(auto &i:v){
        cin>>i.x>>i.y>>i.w;
        vx.pb(i.x);
        vy.pb(i.y);
    }
    sort(all(vx));
    sort(all(vy));
    vx.erase(unique(all(vx)), vx.end());
    vy.erase(unique(all(vy)), vy.end());
    for(auto &i:v){
        i.x=lower_bound(all(vx), i.x)-vx.begin();
        i.y=lower_bound(all(vy), i.y)-vy.begin();
        swap(i.x, i.y);
    }
    sort(all(v));
    ll ans=0;
    for(int i=0; i<n; i++){
        if(i&&v[i-1].x==v[i].x) continue;
        for(auto &itr:seg) itr={0, 0, 0, 0};
        for(int j=i; j<n; j++){
            update(v[j].y, v[j].w);
            if(j==n-1||v[j].x!=v[j+1].x) ans=max(ans, seg[1].lr);
        }
    }
    cout<<ans;
}
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

int arr[500500];
int seg[2000200];
int lazy[2000200];

int init(int l, int r, int node){
    if(l==r) return seg[node]=arr[l];
    return seg[node]=init(l, mid, node*2)^init(mid+1, r, node*2+1);
}

void lazy_update(int l, int r, int node){
    if(lazy[node]){
        seg[node]^=lazy[node]*((r-l+1)%2);
        if(l^r) lazy[node*2]^=lazy[node], lazy[node*2+1]^=lazy[node];
        lazy[node]=0;
    }
}

int update(int l, int r, int node, int i, int j, int v){
    lazy_update(l, r, node);
    if(j<l||r<i) return seg[node];
    if(i<=l&&r<=j){
        lazy[node]^=v;
        lazy_update(l, r, node);
        return seg[node];
    }
    return seg[node]=update(l, mid, node*2, i, j, v)^update(mid+1, r, node*2+1, i, j, v);
}

int query(int l, int r, int node, int i, int j){
    lazy_update(l, r, node);
    if(j<l||r<i) return 0;
    if(i<=l&&r<=j) return seg[node];
    return query(l, mid, node*2, i, j)^query(mid+1, r, node*2+1, i, j);
}

int main(){
    fastio
    int n, m, a, b, c, d;
    cin>>n;
    for(int i=1; i<=n; i++) cin>>arr[i];
    init(1, n, 1);
    cin>>m;
    for(;m--;){
        cin>>a>>b;
        b++;
        if(a==1){
            cin>>c>>d;
            c++;
            update(1, n, 1, b, c, d);
        }
        else cout<<query(1, n, 1, b, b)<<"\n";
    }
}
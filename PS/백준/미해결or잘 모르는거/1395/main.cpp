#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define X first
#define Y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define mid ((l+r)>>1)

using namespace std;
typedef long long ll;
const int dx[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

int seg[400400];
int lazy[400400];

void lazy_update(int l, int r, int node){
    if(lazy[node]){
        seg[node]=(r-l+1)-seg[node];
        if(l^r) lazy[node*2]=!lazy[node*2], lazy[node*2+1]=!lazy[node*2+1];
        lazy[node]=0;
    }
}

int update(int l, int r, int node, int i, int j){
    lazy_update(l, r, node);
    if(j<l||r<i) return seg[node];
    if(i<=l&&r<=j){
        seg[node]=(r-l+1)-seg[node];
        if(l^r) lazy[node*2]=!lazy[node*2], lazy[node*2+1]=!lazy[node*2+1];
        return seg[node];
    }
    return seg[node]=update(l, mid, node*2, i, j)+update(mid+1, r, node*2+1, i, j);
}

int query(int l, int r, int node, int i, int j){
    lazy_update(l, r, node);
    if(j<l||r<i) return 0;
    if(i<=l&&r<=j) return seg[node];
    return query(l, mid, node*2, i, j)+query(mid+1, r, node*2+1, i, j);
}

int main(){
    fastio
    int n, m, a, b, c;
    cin>>n>>m;
    for(;m--;){
        cin>>a>>b>>c;
        if(a) cout<<query(1, n, 1, b, c)<<"\n";
        else update(1, n, 1, b, c);
    }
}
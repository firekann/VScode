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

int n;
int arr[1000100];
int seg[4000400];
int lzy[4000400];

int init(int l, int r, int node){
    if(l==r) return seg[node]=arr[l];
    return seg[node]=init(l, mid, node*2)+init(mid+1, r, node*2+1);
}

void lazy(int l, int r, int node, int i, int j){
    if(!lzy[node]) return;
    seg[node]+=(r-l+1)*lzy[node];
    if(l^r){
        lzy[node*2]+=lzy[node];
        lzy[node*2+1]+=lzy[node];
    }
    lzy[node]=0;
}

void update(int l, int r, int node, int i, int j, int v){
    lazy(l, r, node, i, j);
    if(j<l||r<i) return;
    if(i<=l&&r<=j){
        seg[node]+=(r-l+1)*v;
        if(l^r) lzy[node*2]+=v, lzy[node*2+1]+=v;
        return;
    }
    update(l, mid, node*2, i, j, v), update(mid+1, r, node*2+1, i, j, v);
    seg[node]=seg[node*2]+seg[node*2+1];
}

int query(int l, int r, int node, int i, int j){
    lazy(l, r, node, i, j);
    if(j<l||r<i) return 0;
    if(i<=l&&r<=j) return seg[node];
    return query(l, mid, node*2, i, j)+query(mid+1, r, node*2+1, i, j);
}

int main(){
    fastio
    cin>>n;
    for(int i=1; i<=n; i++) cin>>arr[i];
    init(1, n, 1);
    int q;
    cin>>q;
    for(;q--;){
        int a, b, c;
        cin>>a>>b>>c;
        if(!a) cout<<query(1, n, 1, b, c)<<"\n";
        else{
            int d;
            cin>>d;
            if(a==2) d=-d;
            update(1, n, 1, b, c, d);
        }
    }
}
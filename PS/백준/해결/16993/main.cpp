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
ll arr[100100];
struct Node{ll l, m, r, a;};
Node seg[400400];

Node f(Node a, Node b){
    ll l=max(a.l, a.a+b.l);
    ll m=max({a.m, b.m, a.r+b.l});
    ll r=max(b.r, b.a+a.r);
    ll all=a.a+b.a;
    return {l, m, r, all};
}

Node init(int l, int r, int node){
    if(l==r) return seg[node]={arr[l], arr[l], arr[l], arr[l]};
    return seg[node]=f(init(l, mid, node*2), init(mid+1, r, node*2+1));
}

Node query(int l, int r, int node, int i, int j){
    if(j<l||r<i) return {(int)-1e9, (int)-1e9, (int)-1e9, (int)-1e9};
    if(i<=l&&r<=j) return seg[node];
    return f(query(l, mid, node*2, i, j), query(mid+1, r, node*2+1, i, j));
}

int main(){
    fastio
    int q;
    cin>>n;
    for(int i=1; i<=n; i++) cin>>arr[i];
    init(1, n, 1);
    cin>>q;
    for(;q--;){
        int a, b;
        cin>>a>>b;
        Node ans=query(1, n, 1, a, b);
        cout<<max({ans.l, ans.m, ans.r, ans.a})<<"\n";
    }
}
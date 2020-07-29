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
int arr[50500];
pair<int, int> seg[200200];
pair<int, int> f(pair<int, int> a, pair<int, int> b){
    return {max(a.X, b.X), min(a.Y, b.Y)};
}

pair<int, int> init(int l, int r, int node){
    if(l==r) return seg[node]={arr[l], arr[l]};
    return seg[node]=f(init(l, mid, node*2), init(mid+1, r, node*2+1));
}

pair<int, int> query(int l, int r, int node, int i, int j){
    if(j<l||r<i) return {-1e9, 1e9};
    if(i<=l&&r<=j) return seg[node];
    return f(query(l, mid, node*2, i, j), query(mid+1, r, node*2+1, i, j));
}

int main(){
    fastio
    int q;
    cin>>n>>q;
    for(int i=1; i<=n; i++) cin>>arr[i];
    init(1, n, 1);
    for(;q--;){
        int a, b;
        cin>>a>>b;
        pair<int, int> ans=query(1, n, 1, a, b);
        cout<<ans.X-ans.Y<<"\n";
    }
}
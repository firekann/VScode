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
int seg[200200];

int init(int l, int r, int node){
    if(l==r) return seg[node]=arr[l];
    return seg[node]=max(init(l, mid, node*2), init(mid+1, r, node*2+1));
}

int query(int l, int r, int node, int i, int j){
    if(j<l||r<i) return 0;
    if(i<=l&&r<=j) return seg[node];
    return max(query(l, mid, node*2, i, j), query(mid+1, r, node*2+1, i, j));
}

int main(){
    fastio
    cin>>n;
    for(int i=1; i<=n; i++) cin>>arr[i];
    init(1, n, 1);
    int q;
    cin>>q;
    for(;q--;){
        int a, b;
        cin>>a>>b;
        cout<<query(1, n, 1, a, b)<<" ";
    }
}
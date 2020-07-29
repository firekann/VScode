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

int init(int l, int r, int node){
    if(l==r) return seg[node]=arr[l];
    return seg[node]=init(l, mid, node*2)+init(mid+1, r, node*2+1);
}

void update(int l, int r, int node, int i, int d){
    if(i<l||i>r) return;
    seg[node]+=d;
    if(l!=r) update(l, mid, node*2, i, d), update(mid+1, r, node*2+1, i, d);
}

int query(int l, int r, int node, int i, int j){
    if(j<l||r<i) return 0;
    if(i<=l&&r<=j) return seg[node];
    return query(l, mid, node*2, i, j)+query(mid+1, r, node*2+1, i, j);
}

int main(){
    fastio
    cin>>n;
    for(int i=1; i<=n; i++) cin>>arr[i];
    init(1, n, 1);
    int q1, q2;
    cin>>q1>>q2;
    q1+=q2;
    for(;q1--;){
        int a, b, c;
        cin>>a>>b>>c;
        if(a) cout<<query(1, n, 1, b, c)<<"\n";
        else{
            int d=c-arr[b];
            arr[b]=c;
            update(1, n, 1, b, d);
        }
    }
}
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>

#define mid ((l+r)>>1)

using namespace std;
typedef long long ll;

int seg[8100000];

int update(int l, int r, int node, int i, int v){
    if(i<l||i>r) return seg[node];
    if(l==r) return seg[node]+=v;
    return seg[node]=update(l, mid, node*2, i, v)+update(mid+1, r, node*2+1, i, v);
}

int query(int l, int r, int node, int i){
    if(l==r) return l;
    if(i<=seg[node*2]) return query(l, mid, node*2, i);
    return query(mid+1, r, node*2+1, i-seg[node*2]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int a, b;
        cin>>a>>b;
        if(a==1) update(1, 2000001, 1, b, 1);
        else{
            int t=query(1, 2000001, 1, b);
            update(1, 2000001, 1, t, -1);
            cout<<t<<"\n";
        }
    }
}
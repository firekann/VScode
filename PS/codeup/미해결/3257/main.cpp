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
int lzy[400400];
vector<int> vl;

void lazy(int l, int r, int node){
    if(!lzy[node]) return;
    cout<<l<<" "<<r<<" "<<node<<"\n";
    seg[node]+=(vl[r-1]-vl[l-1]+1)*lzy[node];
    if(l^r){
        lzy[node*2]+=lzy[node];
        lzy[node*2+1]+=lzy[node];
    }
    lzy[node]=0;
}

void update(int l, int r, int node, int i, int j, int v){
    cout<<l<<" "<<r<<" "<<node<<" "<<i<<" "<<j<<"\n";
    lazy(l, r, node);
    if(j<l||r<i) return;
    if(i<=l&&r<=j){
        seg[node]+=(vl[r-1]-vl[l-1]+1)*v;
        if(l^r) lzy[node*2]+=v, lzy[node*2+1]+=v;
        return;
    }
    update(l, mid, node*2, i, j, v), update(mid+1, r, node*2+1, i, j, v);
    seg[node]=seg[node*2]+seg[node*2+1];
}

int query(int l, int r, int node, int i, int j){
    lazy(l, r, node);
    if(j<l||r<i) return 0;
    if(i<=l&&r<=j) return seg[node];
    return query(l, mid, node*2, i, j)+query(mid+1, r, node*2+1, i, j);
}

int main(){
    fastio
    int n;
    int q;
    cin>>q;
    unordered_map<int, int> idx;
    vector<pair<pair<int, int>, pair<int, int>>> vpp(q);
    for(int i=0; i<q; i++){
        int a, b, c;
        cin>>a>>b>>c;
        vl.push_back(b);
        vl.push_back(c);
        vpp[i].X={a, b};
        vpp[i].Y.X=c;
        if(a){
            int d;
            cin>>d;
            vpp[i].Y.Y=d;
        }
    }
    sort(all(vl));
    vl.erase(unique(all(vl)), vl.end());
    n=sz(vl);
    int t=1;
    for(auto itr:vl) idx[itr]=t++;
    for(int i=0; i<q; i++){
        cout<<idx[vpp[i].X.Y]<<", "<<idx[vpp[i].Y.X]<<"\n";
        if(vpp[i].X.X) update(1, n, 1, idx[vpp[i].X.Y], idx[vpp[i].Y.X], vpp[i].Y.Y);
        else cout<<query(1, n, 1, idx[vpp[i].X.Y], idx[vpp[i].Y.X])<<"\n";
        cout<<"==================\n";
        for(int i=1; i<=n; i++){
            for(int j=i; j<=n; j++){
                cout<<i<<", "<<j<<" "<<query(1, n, 1, i, j)<<"\n";
            }
        }
        cout<<"==================\n";
    }
    
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j++){
            cout<<i<<", "<<j<<" "<<query(1, n, 1, i, j)<<"\n";
        }
    }
}

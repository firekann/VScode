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

struct node{
    int x, y1, y2, end;

    bool operator<(const node &p)const{
        if(x==p.x) return end>p.end;
        return x<p.x;
    }
};

const int treeMAX=1e5, half=5e4;
int seg[30000];
int lzy[30000];
vector<node> vp;

int update(int l, int r, int node, int i, int j, int v){
    if(j<l||r<i) return lzy[node]?r-l+1:seg[node];
    if(i<=l&&r<=j){
        lzy[node]+=v;
        return lzy[node]?r-l+1:seg[node];
    }
    seg[node]=update(l, mid, node*2, i, j, v)+update(mid+1, r, node*2+1, i, j, v);
    return lzy[node]?r-l+1:seg[node];
}

int main(){
    fastio
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int x1, x2, y1, y2;
        cin>>x1>>y1>>x2>>y2;
        vp.push_back({x1, y1+half, y2+half-1, 1});
        vp.push_back({x2, y1+half, y2+half-1, -1});
    }
    sort(all(vp));
    int x=vp[0].x;
    ll ans=0;
    for(auto itr:vp){
        ans+=(itr.x-x)*seg[1];
        update(0, treeMAX, 1, itr.y1, itr.y2, itr.end);
        x=itr.x;
    }
    cout<<ans;
}
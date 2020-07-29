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

vector<int> arr(1000100);
vector<ll> v(500500);
vector<ll> seg(2002000);

void update(int l, int r, int node, int i){
    if(i<l||i>r) return;
    seg[node]+=1;
    if(l^r) update(l, mid, node*2, i), update(mid+1, r, node*2+1, i);
}

ll sum(int l, int r, int node, int s, int e){
    if(s>r||e<l) return 0;
    if(s<=l&&r<=e) return seg[node];
    return sum(l, mid, node*2, s, e)+sum(mid+1, r, node*2+1, s, e);
}

int main(){
    fastio
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        ll tmp;
        cin>>tmp;
        arr[tmp]=i;
    }
    for(int i=0; i<n; i++){
        ll tmp;
        cin>>tmp;
        v[i]=arr[tmp];
    }
    ll ans=0;
    for(int i=0; i<n; i++){
        int tmp=v[i]+1;
        ans+=sum(1, n, 1, tmp+1, n);
        update(1, n, 1, tmp);
    }
    cout<<ans;
}
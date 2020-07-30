#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define X first
#define Y second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mid ((l+r)>>1)

using namespace std;
typedef long long ll;
const int dx[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

int main(){
    fastio
    int n, k;
    cin>>n>>k;
    vector<int> edge(n, -1);
    bool ck=true;
    for(int i=0; i<n; i++){
        int tmp;
        cin>>tmp;
        edge[i]=tmp;
        if(tmp==k) ck=false;
    }
    if(ck){
        cout<<"-1";
        return 0;
    }
    int idx=edge[0];
    for(int i=0; i<=n; i++){
        if(idx==k){
            cout<<i+1;
            return 0;
        }
        if(edge[idx]==-1){
            cout<<"-1";
            return 0;
        }
        idx=edge[idx];
    }
    cout<<"-1";
}
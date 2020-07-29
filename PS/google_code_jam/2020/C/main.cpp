#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define X first
#define Y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;
typedef long long ll;
const int dx[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

vector<pair<ll, ll>> v;
int f(int idx, int velue, int td, int nc){
    int tmp=0;
    if(idx==sz(v)-1){
        tmp=td-v[idx].X;
        if(tmp<1) return 0;
        tmp=0;
        for(int i=0; i<v[idx].X&&nc; i++){
            for(int j=0; j<v[idx].Y&&nc; j+=velue){
                nc--, tmp++;
            }
        }
        if(nc<=0) return tmp;
        else return 1e9;
    }
    tmp=td-v[idx].X;
    if(tmp<1) return 0;
    tmp=0;
    for(int i=0; i<v[idx].X&&nc; i++){
        for(int j=0; j<v[idx].Y&&nc; j+=velue){
            nc--, tmp++;
        }
    }
    int tt=0;
    if(v[idx].Y==velue) tt=v[idx].X;
    return min(tmp+f(idx+1, velue, td, nc), f(idx+1, velue, td, td-tt));
}

int main(){
    fastio
    int T;
    cin>>T;
    for(int t=1; t<=T; t++){
        cout<<"Case #"<<t<<": \n";
        int n, d;
        cin>>n>>d;
        vector<ll> a(n);
        map<ll, ll> m;
        v.clear();
        for(int i=0; i<n; i++){
            cin>>a[i];
            if(m.count(a[i])) m[a[i]]++;
            else m[a[i]]=1;
        }
        for(auto i:m) v.push_back({i.Y, i.X});
        sort(all(v));
        int ans=1e9;
        for(int i=1; i<=20; i++){
            int tmp=f(0, i, d, d);
            cout<<i<<" "<<tmp<<"\n";
            ans=min(ans, tmp);
        }
        cout<<ans;
        cout<<"\n";
    }
}
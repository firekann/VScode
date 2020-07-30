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

using namespace std;
typedef long long ll;
const int dx[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

int main(){
    int n;
    cin>>n;
    vector<pii> v;
    for(int i=0; i<n; i++){
        int a, b;
        cin>>a>>b;
        v.pb({a, b});
    }
    int ans=-1e9;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                ans=max(ans, abs(v[i].X*v[j].Y+v[j].X*v[k].Y+v[k].X*v[i].Y-v[j].X*v[i].Y-v[k].X*v[j].Y-v[i].X*v[k].Y));    
            }
        }
    }
    if(ans%2) printf("%d.5", ans/2);
    else printf("%d", ans/2);
}
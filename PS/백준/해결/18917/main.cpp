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

int main(){
    fastio
    ll sum=0;
    ll xr=0;
    int t;
    cin>>t;
    while(t--){
        int a;
        cin>>a;
        if(a==1){
            cin>>a;
            sum+=a;
            xr^=a;
        }
        else if(a==2){
            cin>>a;
            sum-=a;
            xr^=a;
        }
        else if(a==3) cout<<sum<<"\n";
        else cout<<xr<<"\n";
    }
}
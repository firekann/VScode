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
    fastio
    while(1){
        double h, u, d, f;
        cin>>h>>u>>d>>f;
        if(h==0.0) break;
        bool flag=true;
        double up=0, cnt=0;
        double mu=u*f/100;
        for(;1;){
            cnt++;
            up+=u;
            if(up>h){flag=false; break;}
            if(u>0) u-=mu;
            if(u<0) u=0;
            up-=d;
            if(up<0.0) break;
        }
        if(flag) cout<<"failure on day "<<cnt<<"\n";
        else cout<<"success on day "<<cnt<<"\n";
    }
}
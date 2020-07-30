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
    int r, c, a, b;
    cin>>r>>c>>a>>b;
    int cntr=0;
    int cntc=0;
    int flag=0;
    int ck, ckc=0;
    for(int i=0; i<r*a; i++){
        if(flag==a) flag=0, ckc=ckc?0:1;
        if(ckc) ck=1;
        else ck=0;
        for(int j=0; j<c*b; j++){
            if(ck) cout<<".";
            else cout<<"X";
            cntc++;
            if(cntc==b) cntc=0, ck=ck?0:1;
        }
        flag++;
        cout<<"\n";
    }
}
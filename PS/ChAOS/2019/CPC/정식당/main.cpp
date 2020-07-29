#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long lli;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c;
    cin>>a>>b>>c;
    map<string, int> ma;
    map<string, int> mb;
    string t;
    int tmpi;
    while(a--){
        cin>>t>>tmpi;
        ma[t]=tmpi;
    }
    while(b--){
        cin>>t>>tmpi;
        mb[t]=tmpi;
    }
    while(c--) cin>>t;
    int n;
    cin>>n;
    lli sa=0, sb=0, bc=0;
    while(n--){
        cin>>t;
        if(ma.count(t)!=0) sa+=ma[t];
        else if(mb.count(t)!=0) sb+=mb[t];
        else bc++;
    }
    if(sa>=20000&&sa+sb>=50000&&bc==1) cout<<"Okay";
    else if(sa>=20000&&bc==0) cout<<"Okay";
    else if(sa!=0&&sb==0&&bc==0) cout<<"Okay";
    else cout<<"No";
}

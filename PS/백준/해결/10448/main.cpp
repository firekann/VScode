#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long lli;

vector<int> a;

bool f(int n){
    for(int i=0; i<a.size(); i++)
            for(int j=0; j<a.size(); j++)
                for(int k=0; k<a.size(); k++)
                    if(a[i]+a[j]+a[k]==n) return 1;
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    vector<int> v(t);
    int maxv=-1;
    for(int i=0; i<t; i++){
        cin>>v[i];
        maxv=max(maxv, v[i]);
    }
    int tmp=0;
    for(int i=1; tmp<=maxv; i++){
        tmp+=i;
        a.push_back(tmp);
    }
    for(int i=0; i<t; i++){
        cout<<f(v[i])<<"\n";
    }
}

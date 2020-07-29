#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long lli;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    vector<int> v;
    for(int i=0; i<4; i++){
        int tmp;
        cin>>tmp;
        for(int j=0; j<tmp; j++){
            v.push_back(i);
        }
    }
    int maxv=-1e9, minv=1e9;
    do{
        int tmp=a[0];
        for(int i=0; i<n-1; i++){
            if(v[i]==0) tmp+=a[i+1];
            else if(v[i]==1) tmp-=a[i+1];
            else if(v[i]==2) tmp*=a[i+1];
            else if(v[i]==3) tmp/=a[i+1];
        }
        maxv=max(maxv, tmp);
        minv=min(minv, tmp);
    }while (next_permutation(v.begin(), v.end()));
    cout<<maxv<<"\n"<<minv;
}
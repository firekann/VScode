#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define mid ((l+r)>>1)

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin>>n>>k;
    int l=0, r=k, ans;
    while(l<=r){
        ll tmp=0;
        for(int i=1; i<=n; i++) tmp+=min(mid/i, n);
        if(k>tmp) l=mid+1;
        else ans=mid, r=mid-1;
    }
    cout<<ans;
}
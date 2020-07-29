#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long lli;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, ans=1e9;
    cin>>n;
    vector<int> v;
    for(int i=0; i<n; i++) v.push_back(i<n/2?0:1);
    int a[21][21];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>a[i][j];
    do{
        int tmp[2]={0,0};
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(v[i]==v[j]) tmp[v[i]]+=a[i][j];
        ans=min(ans, abs(tmp[0]-tmp[1]));
    }while (next_permutation(v.begin(), v.end()));
    cout<<ans;
}
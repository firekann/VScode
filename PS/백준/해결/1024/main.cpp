#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, l;
    cin>>n>>l;
    for(int i=l; i<=100; i++){
        int tmp=n-i*(i+1)/2;
        if(tmp%i==0){
            int t=tmp/i+1;
            if(t>=0){
                for(int j=0; j<i; j++) cout<<t+j<<" ";
                return 0;
            }
        }
    }
    cout<<"-1";
}
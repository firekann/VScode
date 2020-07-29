#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin>>a>>b;
    if(b<45){
        b+=60;
        a--;
        if(a<0) a=23;
    }
    cout<<a<<" "<<b-45;
}
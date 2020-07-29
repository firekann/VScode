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
    while(1){
        ll n, pi;
        cin>>n;
        if(!n) break;
        pi=n;
        for(ll i=2; i*i<=n; i++){
            if(n%i==0){
                pi=pi/i*(i-1);
            }
            while(n%i==0){
                n/=i;
            }
        }
        if(n!=1){
            pi=pi/n*(n-1);
        }
        cout<<pi<<"\n";
        }
}

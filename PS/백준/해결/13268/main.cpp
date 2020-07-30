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
    int n;
    cin>>n;
    n%=100;
    for(int i=0; i<=4; i++){
        for(int j=1; j<=i; j++){
            n-=5;
            if(n<=0){
                cout<<j;
                return 0;
            }
        }
        n++;
        for(int j=i; j>=1; j--){
            n-=5;
            if(n<=0){
                cout<<j;
                return 0;
            }
        }
        n--;
        if(n<=0){
            cout<<"0";
            return 0;
        }
    }
}
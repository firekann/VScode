
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
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        if(k<n) cout<<k<<"\n";
        else if(k==n) cout<<k+1<<"\n";
        else{
            int tmp=k/(n-1);
            cout<<(n*tmp+k%(n-1)-(k%(n-1)?0:1))<<"\n";
        }
    }
}
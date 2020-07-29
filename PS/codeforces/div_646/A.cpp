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
        int a, b;
        cin>>a>>b;
        int cnto, cnte;
        cnto=cnte=0;
        for(int i=0; i<a; i++){
            int tmp;
            cin>>tmp;
            if(tmp%2) cnto++;
            else cnte++;
        }
        if(cnte==0){
            if(b%2) cout<<"Yes\n";
            else cout<<"No\n";
        }
        else if(cnto==0) cout<<"No\n";
        else{
            if(a==b){
                if(cnto%2) cout<<"Yes\n";
                else cout<<"No\n";
            }
            else cout<<"Yes\n";
        }
    }
}
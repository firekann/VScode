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
        int a, b, c, d, e, f;
        cin>>a>>b>>c>>d>>e>>f;
        int differ=(d-a)*(d-a)+(e-b)*(e-b);
        int sum=(c+f)*(c+f);
        int dif=(c-f)*(c-f);
        if(!differ){
            if(!dif) cout<<"-1\n";
            else cout<<"0\n";
        }
        else if(differ==sum||differ==dif) cout<<"1\n";
        else if(dif<differ&&differ<sum) cout<<"2\n";
        else cout<<"0\n";
    }
}
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;
typedef long long ll;
const int dx[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

int main(){
    fastio
    int a, b, c, d, e, f;
    cin>>a>>b>>c>>d>>e>>f;
    int x, y;
    for(int i=-999; i<=999; i++){
        for(int j=-999; j<=999; j++){
            if(a*i+b*j==c&&d*i+e*j==f){
                cout<<i<<" "<<j;
                return 0;
            }
        }
    }
}
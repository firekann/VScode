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
        int a, b, c;
        cin>>a>>b>>c;
        if(!a&&!b&&!c) return 0;
        if(((c-a)%b)||((c-a)/b+1)<=0) cout<<"X\n";
        else cout<<(c-a)/b+1<<"\n";
    }
}
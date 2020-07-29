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

vector<pair<int, char>> a(26);
int main(){
    fastio
    string s;
    cin>>s;
    for(int i=0; i<sz(s); i++){
        if(s[i]>96) s[i]-=32;
        a[s[i]-65]={a[s[i]-65].X+1, s[i]};
    }
    sort(all(a));
    if(a[25].X==a[24].X) cout<<"?";
    else cout<<a[25].Y;
}
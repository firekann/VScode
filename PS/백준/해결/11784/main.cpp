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
    string s;
    while(cin>>s){
        string ans="";
        for(int i=0; i<sz(s); i+=2){
            char tmps[3];
            tmps[0]=s[i];
            tmps[1]=s[i+1];
            int tmp=(int)strtol(tmps, NULL, 16);
            ans+=tmp;
        }
        cout<<ans<<"\n";
    }
}
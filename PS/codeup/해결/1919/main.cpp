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

void f(string s, int n, bool ck){
    if(n==s.length()) return;
    if(s[n]!='0') ck=true;
    if(ck) cout<<s[n];
    f(s, n+1, ck);
}

int main(){
    fastio
    string s;
    cin>>s;
    if(s=="0"){
        cout<<"0";
        return 0;
    }
    reverse(all(s));
    f(s, 0, false);
}
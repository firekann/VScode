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
    cin>>s;
    int a, b;
    a=b=0;
    bool ck0, ck1;
    if(s[0]=='1') ck1=true, ck0=false;
    else ck1=false, ck0=true;
    for(int i=1; i<sz(s); i++){
        if(ck0){
            if(s[i]=='1') a++, ck1=true, ck0=false;
        }
        else{
            if(s[i]=='0') b++, ck1=false, ck0=true;
        }
    }
    if(ck0) a++, ck1=true, ck0=false;
    else b++, ck1=false, ck0=true;
    cout<<min(a, b);
}
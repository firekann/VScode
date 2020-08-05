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
#define mid ((l+r)>>1)

using namespace std;
typedef long long ll;
const int dx[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

int kmp(string s){
    vector<int> v(sz(s));
    int start=1, match=0;
    while(start+match<sz(s)){
        if(s[start+match]==s[match]){
            match++;
            v[start+match-1]=match;
        }
        else{
            if(match){
                start+=match-v[match-1];
                match=v[match-1];
            }
            else start++;
        }
    }
    sort(all(v), greater<int>());
    return v[0];
}

int main(){
    fastio
    string s;
    cin>>s;
    int ans=0;
    for(int i=0; i<sz(s); i++) ans=max(ans, kmp(s.substr(i, sz(s))));
    cout<<ans;
}
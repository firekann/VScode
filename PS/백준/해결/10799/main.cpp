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

using namespace std;
typedef long long ll;
const int dx[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

int main(){
    fastio
    string s;
    cin>>s;
    int cnt=1;
    int ans=0;
    for(int i=1; i<sz(s); i++){
        if(s[i]=='(') cnt++;
        else{
            cnt--;
            if(s[i-1]=='(') ans+=cnt;
            else ans++;
        }
    }
    cout<<ans;
}
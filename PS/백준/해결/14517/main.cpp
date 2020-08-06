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

const int mod=10007;
ll dp[1010];

int main(){
    fastio
    string s;
    cin>>s;
    int len=sz(s);
    for(int i=0; i<len; i++){
        for(int j=i; j<len; j++){
            if(s[i]==s[j]){
                dp[j]++;
                for(int k=j; k<len-1; k++) dp[j]+=dp[k+1];
                dp[j]%=mod;
            }
        }
    }
    int ans=0;
    for(int i=0; i<len; i++) ans+=dp[i];
    cout<<ans%mod;
}
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

int main(){
    fastio
    int n;
    cin>>n;
    map<int, int> mp;
    n--;
    int tmp;
    ll cnt=0;
    cin>>tmp;
    mp[tmp]=1;
    cout<<"0\n";
    for(;n--;){
        cin>>tmp;
        auto dp=mp.upper_bound(tmp);
        int curdp=0;
        if(dp!=mp.end()) curdp=dp->Y;
        if(dp!=mp.begin()) curdp=max(curdp, (--dp)->Y);
        mp[tmp]=curdp+1;
        cnt+=curdp;
        cout<<cnt<<"\n";
    }
}
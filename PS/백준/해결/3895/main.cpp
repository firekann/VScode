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
    while(1){
        int n, k, m;
        cin>>n>>k>>m;
        if(!n&&!k&&!m) break;
        vector<int> v(n);
        for(int i=0; i<n; i++) v[i]=i+1;
        m--;
        int tmp=n-1;
        for(;sz(v)!=1;){
            v.erase(v.begin()+m);
            m--;
            m+=k;
            if(m>=tmp) m%=tmp;
            tmp--;
        }
        cout<<v[0]<<"\n";
    }
}
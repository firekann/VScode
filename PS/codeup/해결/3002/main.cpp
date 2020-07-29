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
    int n;
    cin>>n;
    map<int, int> mp;
    for(int i=0; i<n; i++){
        int tmp;
        cin>>tmp;
        mp[tmp]=i+1;
    }
    cin>>n;
    for(int i=0; i<n; i++){
        int tmp;
        cin>>tmp;
        if(mp[tmp]) cout<<mp[tmp]<<" ";
        else cout<<"-1 ";
    }
}
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
    vector<int> v(n);
    map<int, int> mp;
    for(int i=0; i<n; i++){
        cin>>v[i];
        if(mp[v[i]]) mp[v[i]]++;
        else mp[v[i]]=1;
    }
    vector<int> tmp;
    tmp=v;
    sort(all(tmp));
    reverse(all(tmp));
    int add=mp[tmp[0]];
    mp[tmp[0]]=1;
    for(int i=1; i<n; i++){
        if(tmp[i]!=tmp[i-1]){
            int t=add;
            add=mp[tmp[i]];
            mp[tmp[i]]=mp[tmp[i-1]]+t;
        }
    }
    for(int i=0; i<n; i++) cout<<v[i]<<" "<<mp[v[i]]<<"\n";
}
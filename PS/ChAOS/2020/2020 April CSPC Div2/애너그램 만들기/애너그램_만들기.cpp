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

map<char, int> ma;
map<char, int> mb;

int main(){
    fastio
    string a, b;
    cin>>a>>b;
    for(auto i:a){
        if(ma.count(i)) ma[i]++;
        else ma[i]=1;
    }
    for(auto i:b){
        if(mb.count(i)) mb[i]++;
        else mb[i]=1;
    }
    int ans=0;
    for(int i='a'; i<='z'; i++){
        if(ma.count(i)&&mb.count(i)) ans+=abs(ma[i]-mb[i]);
        else if(ma.count(i)) ans+=ma[i];
        else ans+=mb[i];
    }
    cout<<ans;
}
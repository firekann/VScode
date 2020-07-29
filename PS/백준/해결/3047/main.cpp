#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<pair<int, char>> v(3);
    for(int i=0; i<3; i++) cin>>v[i].first;
    sort(v.begin(), v.end());
    for(int i=65; i<68; i++) v[i-65].second=i;
    string s;
    cin>>s;
    for(int i=0; i<3; i++){
        for(auto itr:v){
            if(s[i]==itr.second) cout<<itr.first<<" ";
        }
    }
}
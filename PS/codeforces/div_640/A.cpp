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
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int l=sz(s);
        vector<int> v;
        for(int i=0; i<l; i++){
            int tmp=s[i]-'0';
            for(int j=0; j<l-i-1; j++) tmp*=10;
            if(s[i]!='0') v.push_back(tmp);
        }
        cout<<sz(v)<<"\n";
        for(auto i:v) cout<<i<<" ";
        cout<<"\n";
    }
}
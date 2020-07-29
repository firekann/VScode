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
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0; i<n; i++) v[i]=i+1;
        do{
            bool ck=true;
            for(int i=1; i<n; i++){
                if(abs(v[i]-v[i-1])>4||abs(v[i]-v[i-1])<2){
                    ck==false;
                    break;
                }
            }
            if(!ck){
                for(auto i:v) cout<<i<<" ";
                cout<<"\n";
                break;
            }
	    }while(next_permutation(v.begin(),v.end()));
    }
}
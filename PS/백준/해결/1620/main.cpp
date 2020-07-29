#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define mid ((l+r)>>1)

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    vector<pair<string, int>> v(n);
    vector<string> vs(n);
    for(int i=0; i<n; i++){
        pair<string, int> t;
        cin>>t.first;
        t.second=i+1;
        v[i]=t;
        vs[i]=t.first;
    }
    sort(v.begin(), v.end());
    //for(auto i:v) cout<<i.second<<" "<<i.first<<"\n";
    while(m--){
        char t[21];
        cin>>t;
        if(atoi(t)){
            int num=atoi(t)-1;
            cout<<vs[num]<<"\n";
        }
        else{
            string s(t);
            int l=0, r=n;
            while(l<r){
                if(s==v[mid].first) break;
                else if(s>v[mid].first) l=mid+1;
                else r=mid-1;
            }
            cout<<v[mid].second<<"\n";
        }
    }
}


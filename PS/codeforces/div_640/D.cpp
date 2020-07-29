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
        for(int i=0; i<n; i++) cin>>v[i];
        int l=1, r=sz(v)-1;
        int st=v[0];
        int a=v[0];
        int b=0;
        int cnt=0;
        for(int i=1; 1; i++){
            cnt++;
            int tmps=0;
            if(i%2){
                while(tmps<=st&&l<=r) tmps+=v[r--];
                b+=tmps;
                if(tmps<=st){
                    if(tmps) cnt++;
                    break;
                }
                st=tmps;
            }
            else{
                while(tmps<=st&&l<=r) tmps+=v[l++];
                a+=tmps;
                if(tmps<=st){
                    if(tmps) cnt++;
                    break;
                }
                st=tmps;
            }
        }
        cout<<cnt<<" "<<a<<" "<<b<<"\n";
    }
}
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
        int x1, x2, y1, y2;
        cin>>x1>>y1>>x2>>y2>>n;
        int ans=0;
        for(int i=0; i<n; i++){
            int x, y, r;
            bool f1, f2;
            f1=f2=false;
            cin>>x>>y>>r;
            int tx=(x-x1)*(x-x1);
            int ty=(y-y1)*(y-y1);
            if(r*r>tx+ty) f1=true;
            tx=(x-x2)*(x-x2);
            ty=(y-y2)*(y-y2);
            if(r*r>tx+ty) f2=true;
            if((f1||f2)&&(f1!=f2)) ans++;
        }
        cout<<ans<<"\n";
    }   
}
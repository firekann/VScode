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
        int n, k;
        cin>>n>>k;
        int tmpn=n;
        if(k==1) cout<<"YES\n"<<n<<"\n";
        else if(k>n) cout<<"NO\n";
        else{
            for(int i=0; i<k-1; i++) tmpn--;
            if(tmpn>0&&tmpn%2==1){
                cout<<"YES\n";
                for(int i=0; i<k-1; i++) cout<<"1 ";
                cout<<tmpn<<"\n";
            }
            else{
                tmpn=n;
                for(int i=0; i<k-1; i++) tmpn-=2;
                if(tmpn>0&&tmpn%2==0){
                    cout<<"YES\n";
                    for(int i=0; i<k-1; i++) cout<<"2 ";
                    cout<<tmpn<<"\n";
                }
                else cout<<"NO\n";
            }
        }
    }
}
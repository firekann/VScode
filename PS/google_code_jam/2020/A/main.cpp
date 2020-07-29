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

/*
    int T;
    cin>>T;
    for(int t=1; t<=T; t++){
        cout<<"Case #"<<t<<": ";

        cout<<"\n";
    }
*/
int arr[2020][2020];

int main(){
    fastio
    int T;
    cin>>T;
    for(int t=1; t<=T; t++){
        cout<<"Case #"<<t<<": ";
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        bool flag=true;
        for(int i=0; i<=sz(s); i++){
            if(abs(n)+abs(m)<=i){
                flag=false;
                cout<<i;
                break;
            }
            if(s[i]=='N') m++;
            else if(s[i]=='S') m--;
            else if(s[i]=='W') n--;
            else if(s[i]=='E') n++;
        }
        if(flag) cout<<"IMPOSSIBLE";
        cout<<"\n";
    }
    
}
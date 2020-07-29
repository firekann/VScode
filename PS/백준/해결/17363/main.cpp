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
    int n, m;
    cin>>n>>m;
    char arr[100][100];
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) cin>>arr[i][j];
    swap(n, m);
    for(int j=n-1; j>=0; j--){
        for(int i=0; i<m; i++){
            if(arr[i][j]=='-') cout<<"|";
            else if(arr[i][j]=='|') cout<<"-";
            else if(arr[i][j]=='/') cout<<"\\";
            else if(arr[i][j]=='\\') cout<<"/";
            else if(arr[i][j]=='^') cout<<"<";
            else if(arr[i][j]=='<') cout<<"v";
            else if(arr[i][j]=='v') cout<<">";
            else if(arr[i][j]=='>') cout<<"^";
            else cout<<arr[i][j];
        }
        cout<<"\n";
    }
}
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
    int arr[100][10000];
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) cin>>arr[i][j];
    int cnt=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            bool flag=true;
            for(int k=0; k<m; k++){
                for(int q=k+1; q<m; q++){
                    if(!((arr[i][k]<arr[i][q]&&arr[j][k]<arr[j][q])||(arr[i][k]==arr[i][q]&&arr[j][k]==arr[j][q])||(arr[i][k]>arr[i][q]&&arr[j][k]>arr[j][q]))){
                        flag=false;
                        break;
                    }
                }
            }
            if(flag) cnt++;
        }
    }
    cout<<cnt;
}
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
    int arr[10]={0}, sum=0;
    for(int i=0; i<9; i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(i!=j){
                if(sum-(arr[i]+arr[j])==100){
                    arr[i]=0;
                    arr[j]=0;
                    sort(arr, arr+9);
                    for(int k=2; k<9; k++) cout<<arr[k]<<"\n";
                    return 0;
                }
            }
        }
    }
}
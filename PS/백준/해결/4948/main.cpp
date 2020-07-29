#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

using namespace std;
typedef long long ll;
const int dx[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

int main(){
    fastio;
    int num=247000;
    int a[num]={0, 1};
    for(int i=2; i<=sqrt(num); i++){
        if(a[i]==1) continue;
        for(int j=2*i; j<=num; j+=i) a[j]=1;
    }
    while(1){
        int n;
        cin>>n;
        if(!n) return 0;
        int cnt=0;
        for(int i=n+1; i<=2*n; i++)
            if(!a[i]) cnt++;
        cout<<cnt<<"\n";
    }
}
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

int a[1001]={0, 1};

int main(){
    fastio;
    int n, k;
    cin>>n>>k;
    vector<int> v;
    for(int i=2; i<=n; i++){
        if(a[i]==1) continue;
        for(int j=i; j<=n; j+=i){
            if(!a[j]) v.push_back(j);
            a[j]=1;
        }
    }
    cout<<v[k-1];
}
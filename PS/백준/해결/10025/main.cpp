#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define X first
#define Y second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;
typedef long long ll;
const int dx[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

int arr[1000010];

int main(){
    fastio
    int n, k;
    cin>>n>>k;
    for(int i=0; i<n; i++){
        int a, b;
        cin>>a>>b;
        arr[b]=a;
    }
    int maxv=-1e9;
    int sum=0;
    int range=0;
    for(int i=0; i<=1000000; i++){
        if(range==k*2+1) sum-=arr[i-range];
        else range++;
        sum+=arr[i];
        maxv=max(maxv, sum);
    }
    cout<<maxv;
}
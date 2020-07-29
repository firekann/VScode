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

typedef struct{
    int num, idx, pos;
} zip;


int main(){
    fastio
    int n;
    cin>>n;
    map<int, int> m;
    vector<pair<int, pair<int, int>>> v(n);
    for(int i=0; i<n; i++){
        v[i].Y.X=i;
        cin>>v[i].X;
    }
    sort(all(v));
    int idx=0;
    v[0].Y.Y=idx;
    for(int i=1; i<n; i++){
        if(v[i].X!=v[i-1].X) idx++;
        v[i].Y.Y=idx;
    }
    for(int i=0; i<n; i++) swap(v[i].Y.X, v[i].X);
    sort(all(v));
    for(auto i:v) cout<<i.Y.Y<<" ";
}
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

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
    if(a.X.X==b.X.X){
        if(a.X.Y==b.X.Y) return a.Y<b.Y;
        else return a.X.Y>b.X.Y;
    }
    else return a.X.X>b.X.X;
}

int main(){
    fastio
    int n;
    cin>>n;
    vector<pair<pair<int, int>, int>> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i].X.X>>v[i].X.Y;
        v[i].Y=i+1;
    }
    sort(all(v), cmp);
    for(int i=0; i<n; i++) cout<<v[i].Y<<" "<<v[i].X.X<<" "<<v[i].X.Y<<"\n";
}
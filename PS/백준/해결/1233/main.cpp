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

bool cmp(const pii a, const pii b){
    if(a.X==b.X) return a.Y<b.Y;
    return a.X>b.X;
}

int main(){
    fastio
    int s1, s2, s3;
    cin>>s1>>s2>>s3;
    vector<pii> v(81);
    for(int i=1; i<=s1; i++) for(int j=1; j<=s2; j++) for(int k=1; k<=s3; k++) v[i+j+k]={v[i+j+k].X+1, i+j+k};
    sort(all(v), cmp);
    cout<<v[0].Y;
}
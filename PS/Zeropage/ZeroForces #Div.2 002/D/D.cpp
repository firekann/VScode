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
#define mid ((l+r)>>1)

using namespace std;
typedef long long ll;
const int dx[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

int n;
vector<string> v;
int cnt;

void col(int a, int b, int len){
    if(b==n||v[a][b]=='X'){
        if(len>1) cnt++;
        if(b<n) col(a, b+1, 0);
    }
    else col(a, b+1, len+1);
}

void row(int a, int b, int len){
    if(a==n||v[a][b]=='X'){
        if(len>1) cnt++;
        if(a<n) row(a+1, b, 0);
    }
    else row(a+1, b, len+1);
}

int main(){
    fastio
    cin>>n;
    v.resize(n);
    for(auto &i:v) cin>>i;
    for(int i=0; i<n; i++) col(i, 0, 0);
    int c=cnt;
    cnt=0;
    for(int i=0; i<n; i++) row(0, i, 0);
    int r=cnt;
    cout<<c<<" "<<r;
}
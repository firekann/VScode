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

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    return answer;
}

int main(){
    fastio
    int n;
    cin>>n;
    vector<vector<int>> vv;
    vv.resize(n);
    for(auto &i:vv){
        i.resize(n);
        for(auto &j:i) cin>>j;
    }
    int m;
    cin>>m;
    vector<int> v(m);
    for(auto &i:v) cin>>i;
    cout<<solution(vv, v);
}
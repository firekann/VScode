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

int main(){
    fastio
    int n;
    cin>>n;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for(;n--;){
        int tmp;
        cin>>tmp;
        if(tmp) pq.push({abs(tmp), tmp});
        else{
            if(pq.empty()) cout<<"0\n";
            else{
                cout<<pq.top().Y<<"\n";
                pq.pop();
            }
        }
    }
}
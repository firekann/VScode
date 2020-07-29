#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
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

const int NODE=3e5+10;
vector<int> edge[NODE];
ll D, G;

int main(){
    fastio
    int n;
    cin>>n;
    vector<pii> mid_edge;
    for(int i=0; i<n-1; i++){
        int a, b;
        cin>>a>>b;
        edge[a].pb(b);
        edge[b].pb(a);
        mid_edge.pb({a, b});
    }
    for(int i=1; i<=n; i++){
        ll tmp=sz(edge[i]);
        G+=tmp*(tmp-1)*(tmp-2)/6;
    }
    for(auto itr:mid_edge){
        ll tmp=(sz(edge[itr.X])-1)*(sz(edge[itr.Y])-1);
        D+=tmp;
    }
    if(D==G*3) cout<<"DUDUDUNGA";
    else if(D>G*3) cout<<"D";
    else cout<<"G";
}

/*
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;
typedef long long ll;
const int dx[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

const int NODE=3e5+10;
vector<int> edge[NODE];
vector<int> redge[NODE];
vector<bool> visit(NODE);
int D, G;
int c[300010][10];
bool ck[NODE];

int comb(int n, int r) {
    if(n == r || r == 0) return 1;
    if(c[n][r] != 0) return c[n][r];
    return c[n][r] = comb(n - 1, r - 1) + comb(n - 1, r);
}

int main(){
    fastio
    int n;
    cin>>n;
    for(int i=0; i<n-1; i++){
        int a, b;
        cin>>a>>b;
        edge[a].pb(b);
        edge[b].pb(a);
    }
    for(int i=1; i<=n; i++){
        int size_of_edge=sz(edge[i])+sz(redge[i]);
        if(size_of_edge>=3) G+=comb(size_of_edge, 3);
        ck[i]=1;
        for(auto itr1:edge[i]){
            for(auto itr2:edge[itr1]){
                for(auto itr3:edge[itr2]){
                    if(!ck[itr3]) D++;
                    else ck[itr3]=1;
                }
            }
        }
    }
    cout<<"D : "<<D<<" G : "<<G<<"\n";
    if(D==G*3) cout<<"DUDUDUNGA";
    else if(D>G*3) cout<<"D";
    else cout<<"G";
}
*/
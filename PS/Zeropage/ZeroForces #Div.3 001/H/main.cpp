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

vector<pair<int, int>> edge[1000];
queue<pair<int, int>> q;
int path[1000]={0};

int main(){
    fastio
    int p, w, c, v;
    cin>>p>>w>>c>>v;
    for(int i=0; i<w; i++){
        int a, b, c;
        cin>>a>>b>>c;
        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
    }
    path[c]=1e9;
    q.push({c, path[c]});
    while(!q.empty()){
        pair<int, int> tmp=q.front();
        q.pop();
        for(auto itr:edge[tmp.X]){
            int mincost=min(tmp.Y, itr.Y);
            if(path[itr.X]<mincost){
                path[itr.X]=mincost;
                q.push({itr.X, mincost});
            }
        }
    }
    cout<<path[v];
}
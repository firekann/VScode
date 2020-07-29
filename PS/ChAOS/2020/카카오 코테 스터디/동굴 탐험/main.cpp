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

const int MAXnode=2e5;
vector<int> edge[MAXnode];
int to[MAXnode], from[MAXnode];
bool visit[MAXnode];
set<int> st;

void bfs(int n){
    queue<int> q;
    q.push(n);
    visit[n]=1;
    if(from[0]) return;
    while(!q.empty()){
        int tmp=q.front();
        q.pop();
        from[to[tmp]]=0;
        if(st.find(to[tmp])!=st.end()){
            st.erase(to[tmp]);
            q.push(to[tmp]);
            visit[to[tmp]]=1;
        }
        for(auto itr:edge[tmp]){
            if(visit[itr]) continue;
            if(from[itr]){
                st.insert(itr);
                continue;
            }
            visit[itr]=1;
            q.push(itr);
        }
    }
    
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    bool answer = true;
    for(auto i:path){
        edge[i[0]].pb(i[1]);
        edge[i[1]].pb(i[0]);
    }
    for(auto i:order){
        to[i[0]]=i[1];
        from[i[1]]=i[0];
    }
    bfs(0);
    for(int i=0; i<n; i++) if(!visit[i]) return false;
    return answer;
}

int main(){
    fastio
    int n;
    cin>>n;
    int pl, ol;
    cin>>pl>>ol;
    vector<vector<int>> p(pl);
    vector<vector<int>> o(ol);
    for(auto &i:p){
        int a, b;
        cin>>a>>b;
        i.pb(a);
        i.pb(b);
    }
    for(auto &i:o){
        int a, b;
        cin>>a>>b;
        i.pb(a);
        i.pb(b);
    }
    cout<<solution(n, p, o);
}
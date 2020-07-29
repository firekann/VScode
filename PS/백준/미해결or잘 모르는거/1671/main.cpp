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

typedef struct shark{
    int size, speed, intel;
} shark;

vector<int> conct[51];
vector<shark> v;
vector<int> visit(51);
vector<int> match(51);

int cmp(shark a, shark b){
    if(a.size==b.size&&a.speed==b.speed&&a.intel==b.intel) return 2;
    if(a.size<b.size) return 0;
    if(a.speed<b.speed) return 0;
    if(a.intel<b.intel) return 0;
    return 1;
}

bool dfs(int n){
    visit[n]=1;
    for(int i=0; i<sz(conct[n]); i++){
        if(match[conct[n][i]]==-1||!visit[match[conct[n][i]]]&&dfs(match[conct[n][i]])){
            match[conct[n][i]]=n;
            return true;
        }
    }
    return false;
}

int main(){
    fastio
    int n;
    cin>>n;
    v.resize(n);
    for(int i=0; i<n; i++) cin>>v[i].size>>v[i].speed>>v[i].intel;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(cmp(v[i], v[j])==1) conct[i].push_back(j);
            if(cmp(v[i], v[j])==2&&i<j) conct[i].push_back(j);
        }
    }
    for(int i=0; i<n; i++) match[i]=-1;
    for(int i=0; i<n; i++){
        for(int j=0; j<=n; j++) visit[j]=0;
        dfs(i);
        for(int j=0; j<=n; j++) visit[j]=0;
        dfs(i);
    }
    int ans=0;
    for(int i=0; i<n; i++) if(match[i]==-1) ans++;
    cout<<ans;
}
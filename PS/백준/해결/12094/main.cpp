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

int n, ans=-1e9;
int maxv[11];
int v[20][20];

bool ck(int prev[20][20]){
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) if(v[i][j]!=prev[i][j]) return false;
    return true; 
}

void roll(int cnt){
    int tmpmax=-1e9;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) tmpmax=max(tmpmax, v[i][j]);
    if(tmpmax<=maxv[cnt]) return;
    if(cnt==10){
        ans=max(ans, tmpmax);
        int tmpans=ans;
        for(int i=cnt; i>0; i--){
            maxv[i]=tmpans;
            tmpans/=2;
        }
        return;
    }
    int tmp[20][20];
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) tmp[i][j]=v[i][j];
    for(int dir=0; dir<4; dir++){
        queue<int> q;
        if(dir==0){
            for(int j=0; j<n; j++){
                for(int i=0; i<n; i++){
                    if(v[i][j]) q.push(v[i][j]);
                    v[i][j]=0;
                }
                for(int i=0; !q.empty();){
                    int tmp=q.front();
                    q.pop();
                    if(!v[i][j]) v[i][j]=tmp;
                    else if(v[i][j]==tmp) v[i++][j]*=2;
                    else v[++i][j]=tmp;
                }
            }
        }
        if(dir==1){
            for(int i=0; i<n; i++){
                for(int j=n-1; j>=0; j--){
                    if(v[i][j]) q.push(v[i][j]);
                    v[i][j]=0;
                }
                for(int j=n-1; !q.empty();){
                    int tmp=q.front();
                    q.pop();
                    if(!v[i][j]) v[i][j]=tmp;
                    else if(v[i][j]==tmp) v[i][j--]*=2;
                    else v[i][--j]=tmp;
                }
            }
        }
        if(dir==2){
            for(int j=0; j<n; j++){
                for(int i=n-1; i>=0; i--){
                    if(v[i][j]) q.push(v[i][j]);
                    v[i][j]=0;
                }
                for(int i=n-1; !q.empty();){
                    int tmp=q.front();
                    q.pop();
                    if(!v[i][j]) v[i][j]=tmp;
                    else if(v[i][j]==tmp) v[i--][j]*=2;
                    else v[--i][j]=tmp;
                }
            }
        }
        if(dir==3){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(v[i][j]) q.push(v[i][j]);
                    v[i][j]=0;
                }
                for(int j=0; !q.empty();){
                    int tmp=q.front();
                    q.pop();
                    if(!v[i][j]) v[i][j]=tmp;
                    else if(v[i][j]==tmp) v[i][j++]*=2;
                    else v[i][++j]=tmp;
                }
            }
        }
        if(ck(tmp)) continue;
        roll(cnt+1);
        for(int i=0; i<n; i++) for(int j=0; j<n; j++) v[i][j]=tmp[i][j];
    }
}

int main(){
    fastio
    cin>>n;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++){cin>>v[i][j]; ans=max(ans, v[i][j]);}
    roll(0);
    cout<<ans;
}
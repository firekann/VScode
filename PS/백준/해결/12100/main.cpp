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

int n, maxv=-1e9;

void roll(int cnt, vector<vector<int>> v, int dir){
    if(cnt==5){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                //cout<<v[i][j]<<" ";
                maxv=max(maxv, v[i][j]);
            }
            //cout<<"\n";
        }
        //cout<<"------------\n";
        return;
    }
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
    for(int i=0; i<4; i++) roll(cnt+1, v, i);
}

int main(){
    fastio
    cin>>n;
    vector<vector<int>> v(n);
    for(int i=0; i<n; i++){
        vector<int> tmpv(n);
        for(int j=0; j<n; j++) cin>>tmpv[j];
        v[i]=tmpv;
    }
    roll(-1, v, -1);
    cout<<maxv;
}
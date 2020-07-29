#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
typedef long long lli;

int n, m;

bool arr_conct[1001][1001];
vector<int> visited;
vector<int> matcha, matchb;
string strarr[1001];

bool dfs(int n){
    if(visited[n]>0) return false;
    visited[n]++;
    for(int i=0; i<m; i++){
        if(arr_conct[n][i]){
            if(matchb[i]==-1||dfs(matchb[i])){
                matcha[n]=i;
                matchb[i]=n;
                return true;
            }
        }
    }
    return false;
}

int matching(){
    matcha=vector<int>(n, -1);
    matchb=vector<int>(m, -1);
    int tmp=0;
    for(int i=0; i<n; i++){
        visited=vector<int>(n, -1);
        if(dfs(i)) tmp++;
    }
    return tmp;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<m; i++) cin>>strarr[i];
    for(int i=0; i<n; i++){
        int tmpcnt;
        cin>>tmpcnt;
        for(int j=0; j<tmpcnt; j++){
            int tmp;
            string tmpstr;
            cin>>tmpstr;
            for(int k=0; k<m; k++){
                if(tmpstr==strarr[k]){
                    tmp=k+1;
                    break;
                }
            }
            arr_conct[i][tmp-1]=1;
        }
    }
    int tmpnum=matching();
    if(tmpnum<n){
        cout<<"NO\n"<<tmpnum;
    }
    else cout<<"YES";
}

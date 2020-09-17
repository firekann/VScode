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

void rotate(vector<vector<int>> &k, int len){
    vector<vector<int>> tmp=k;
    for(int i=0; i<len; i++){
        for(int j=0; j<len; j++){
            tmp[i][j]=k[len-j-1][i];
        }
    }
    k=tmp;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    int lock_len=sz(lock[0]);
    int key_len=sz(key[0]);
    for(int i=-key_len; i<lock_len+key_len; i++){
        for(int j=-key_len; j<lock_len+key_len; j++){
            for(int q=0; q<4; q++){
                bool flag=false;
                vector<vector<int>> tmp_lock=lock;
                for(int ii=0; ii<key_len; ii++){
                    for(int jj=0; jj<key_len; jj++){
                        if(i+ii<0||j+jj<0||i+ii>=lock_len||j+jj>=lock_len) continue;
                        if(tmp_lock[i+ii][j+jj]==key[ii][jj]){
                            flag=true;
                            break;
                        }
                        else tmp_lock[i+ii][j+jj]=1;
                    }
                    if(flag) break;
                }
                for(int ii=0; ii<lock_len; ii++){
                    for(int jj=0; jj<lock_len; jj++){
                        if(!tmp_lock[ii][jj]){
                            flag=true;
                            break;
                        }
                    }
                    if(flag) break;
                }
                if(!flag) return true;
                rotate(key, key_len);
            }
        }
    }
    return answer;
}

int main(){
    fastio
    int n, m;
    cin>>m>>n;
    vector<vector<int>> k(m), l(n);
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            int tmp;
            cin>>tmp;
            k[i].push_back(tmp);
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int tmp;
            cin>>tmp;
            l[i].push_back(tmp);
        }
    }
    cout<<solution(k, l);
}
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

vector<vector<string>> vv;
map<string, bool> mp;
map<map<string, bool>, bool> mmp;
int ans;

void rec(int n, int d){
    if(n==d){
        if(!mmp[mp]){
            mmp[mp]=1;
            ans++;
        }
        cout<<"\n";
        return;
    }
    for(auto i:vv[n]){
        if(!mp[i]){
            mp[i]=1;
            rec(n+1, d);
            mp.erase(i);
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    for(auto i:banned_id){
        vector<string> tmpv;
        for(auto j:user_id){
            if(sz(i)!=sz(j)) continue;
            bool flag=true;
            for(int k=0; k<sz(i); k++){
                if(i[k]=='*') continue;
                if(i[k]!=j[k]){
                    flag=false;
                    break;
                }
            }
            if(flag) tmpv.pb(j);
        }
        vv.pb(tmpv);
    }
    rec(0, sz(vv));
    answer=ans;
    return answer;
}

int main(){
    fastio
    int n, m;
    cin>>n>>m;
    vector<string> vn(n), vm(m);
    for(auto &i:vn) cin>>i;
    for(auto &i:vm) cin>>i;
    cout<<solution(vn, vm);
}
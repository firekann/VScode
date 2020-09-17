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

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    answer.push_back(-1);
    answer.push_back(-1);
    map<string, int> mp;
    for(auto i:gems){
        if(mp[i]);
        else mp[i]=1;
    }
    int end=(int)gems.size();
    int gnum=(int)mp.size();
    int ans=1e9;
    int l=0;
    int r=0;
    map<string, int> cntmp;
    cntmp[gems[0]]=1;
    gems.push_back("");
    while(r<end&&l<=r){
        if((int)cntmp.size()==gnum){
            if(r-l+1<ans){
                answer[0]=l+1;
                answer[1]=r+1;
                ans=r-l+1;
            }
            if(r-l+1==ans){
                if(l+1<answer[0]){
                    answer[0]=l+1;
                    answer[1]=r+1;
                }
            }
            cntmp[gems[l]]--;
            if(cntmp[gems[l]]==0) cntmp.erase(gems[l]);
            l++;
        }
        else{
            r++;
            if(cntmp[gems[r]]) cntmp[gems[r]]++;
            else cntmp[gems[r]]=1;
        }
    }
    return answer;
}

int main(){
    fastio
    int n;
    cin>>n;
    vector<string> vs(n);
    for(int i=0; i<n; i++) cin>>vs[i];
    vector<int> ansv=solution(vs);
    for(auto i:ansv) cout<<i<<"\n";
}
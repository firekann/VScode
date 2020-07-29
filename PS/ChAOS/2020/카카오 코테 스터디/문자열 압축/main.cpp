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

int solution(string s) {
    int answer = 1e9;
    int len=sz(s);
    if(len==1) return 1;
    for(int i=1; i<=len; i++){
        int tmpans=0;
        int cnt=0;
        string pres=s.substr(0, i);
        for(int j=0; j<len; j+=i){
            string tmps=s.substr(j, i);
            if(tmps==pres) cnt++;
            else{
                pres=tmps;
                tmpans+=i;
                tmpans+=cnt>=1000?4:cnt>=100?3:cnt>=10?2:cnt==1?0:1;
                cnt=1;
            }
            if(sz(tmps)<i){ //잘랐는데 남은게 짧을때 예외처리
                tmpans-=i-sz(tmps);
                break;
            }
        }
        if(cnt){ //for문이 끝나고 남은 cnt처리
            tmpans+=i;
            tmpans+=cnt>=1000?4:cnt>=100?3:cnt>=10?2:cnt==1?0:1;
        }
        answer=min(answer, tmpans);
    }
    return answer;
}

int main(){
    fastio
    string s;
    cin>>s;
    cout<<solution(s);
}
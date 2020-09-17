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

string solution(vector<int> numbers, string hand) {
    string answer = "";
    if(hand=="right") hand="R";
    else hand="L";
    vector<pair<int, int>> v;
    v.push_back({-1, -1});
    for(int i=1; i<=4; i++){
        for(int j=1; j<=3; j++){
            v.push_back({i, j});
        }
    }
    pair<int, int> idxr, idxl;
    idxr={4, 1};
    idxl={4, 3};
    for(auto itr:numbers){
        if(itr==1||itr==4||itr==7){
            idxl=v[itr];
            answer+="L";
        }
        else if(itr==3||itr==6||itr==9){
            idxr=v[itr];
            answer+="R";
        }
        else{
            pair<int, int> tmp=v[!itr?11:itr];
            int tmpr=abs(tmp.first-idxr.first)+abs(tmp.second-idxr.second);
            int tmpl=abs(tmp.first-idxl.first)+abs(tmp.second-idxl.second);
            if(tmpr==tmpl){
                answer+=hand;
                if(hand=="R") idxr=tmp;
                else idxl=tmp;
            }
            else if(tmpr<tmpl){
                answer+="R";
                idxr=tmp;
            }
            else{
                answer+="L";
                idxl=tmp;
            }
        }
    }
    return answer;
}

int main(){
    fastio
    int n;
    cin>>n;
    vector<int> numbers(n);
    string hand;
    for(int i=0; i<n; i++) cin>>numbers[i];
    cin>>hand;
    cout<<solution(numbers, hand);
}
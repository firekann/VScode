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

long long cal(long long a, long long b, string opr){
    if(opr=="+") a+=b;
    else if(opr=="-") a-=b;
    else a*=b;
    return a;
}

long long solution(string expression) {
    long long answer = 0;
    string tmps="";
    vector<pair<long long, string>> v;
    for(int i=0; i<expression.length(); i++){
        char tmp=expression[i];
        if('0'<=tmp&&tmp<='9') tmps+=tmp;
        else{
            v.push_back({(long long)atoi(tmps.c_str()), "/"});
            tmps="";
            tmps+=tmp;
            v.push_back({0, tmps});
            tmps="";
        }
    }
    v.push_back({(long long)atoi(tmps.c_str()), "/"});
    string opr[6][3]={{"+", "-", "*"},{"+", "*", "-"},{"-", "+", "*"},{"-", "*", "+"},{"*", "+", "-"},{"*", "-", "+"}};
    for(int k=0; k<6; k++){
        vector<pair<long long, string>> tmpv=v;
        for(int i=0; i<3; i++){
            for(int j=0; j<tmpv.size(); j++){
                if(tmpv[j].second==opr[k][i]){
                    long long tmp=cal(tmpv[j-1].first, tmpv[j+1].first, tmpv[j].second);
                    tmpv[j+1]={tmp, "/"};
                    tmpv.erase(tmpv.begin()+j-1, tmpv.begin()+j+1);
                    j--;
                }
            }
            if(tmpv.size()==1) break;
        }
        answer=max(answer, abs(tmpv[0].first));
    }
    return answer;
}

int main(){
    fastio
    string s;
    cin>>s;
    cout<<solution(s);
}
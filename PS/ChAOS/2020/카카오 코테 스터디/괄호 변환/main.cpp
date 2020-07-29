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

bool ck(string s){
    int cnt=0;
    for(auto i:s){
        if(i=='(') cnt++;
        else cnt--;
        if(cnt<0) return false;
    }
    return true;
}

string f(string s){
    if(s=="") return s;
    string u, v;
    u=v="";
    int l, r;
    l=r=0;
    for(int i=0; i<sz(s); i++){
        if(s[i]=='(') l++;
        else r++;
        if(l==r){
            u=s.substr(0, i+1);
            v=s.substr(i+1);
            break;
        }
    }
    if(ck(u)) return u+f(v);
    string tmps="(";
    tmps+=f(v)+")";
    u=u.substr(1, sz(u)-2);
    for(auto i:u){
        if(i=='(') tmps+=")";
        else tmps+="(";
    }
    return tmps;
}

string solution(string p) {
    string answer = "";
    if(ck(p)) answer=p;
    else answer=f(p);
    return answer;
}

int main(){
    fastio
    string s;
    cin>>s;
    cout<<solution(s);
}
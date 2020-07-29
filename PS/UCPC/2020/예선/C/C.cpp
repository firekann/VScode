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

int x[] = {1, 1, 0, 0}, y[] = {1, 0, 1, 0};

int getval(char c, vector<int> &state) {
    if(c == '1') return 1;
    else if(c == '0') return 0;
    else return state[c - 'a'];
}

int solve(string exp, vector<int> state) {
    if(exp.size() == 1) {
        int a = getval(exp[0], state);
        int ret = 1;
        for(int i = 0;i < state.size();++i)
            if(state[i] == -1) ret *= 2;
        if(a == 0) return ret;
        else if(a == -1) return ret / 2;
        else return 0;
    }

    if(exp.size() == 4) {
        int a = getval(exp[0], state), b = getval(exp[3], state);
        int ret = 1;
        for(int i = 0;i < state.size();++i)
            if(state[i] == -1) ret *= 2;
        if(a == -1 &&  b == -1) return ret / 2;
        else if(a == -1 || b == -1) return ret / 2;
        else if(a != b) return ret;
        else return 0; 
    }

    string cond = "";
    for(char c : exp) {
        if(c == '?') break;
        else cond += c;
    }
    exp = exp.substr(cond.size() + 1);
    string exp1, exp2;
    vector<char> st;
    int i;
    for(i = 0;i < exp.size();++i) {
        char c = exp[i];
        if(c == '?') st.push_back(c);
        else if(c == ':') {
            if(st.empty()) break;
            else st.pop_back();
        }
    }
    exp1 = exp.substr(0, i);
    exp2 = exp.substr(i + 1);

    int ret = 0;
    auto v = state;
    if(cond.size() == 1) {
        int a = getval(cond[0], state);
        if(a == -1) {
            v[cond[0] - 'a'] = 1;
            ret += solve(exp1, v);
            v[cond[0] - 'a'] = 0;
            ret += solve(exp2, v);
        }
        else if(a == 1) ret = solve(exp1, v);
        else ret = solve(exp2, v);
        return ret;
    }
    int a = getval(cond[0], v), b = getval(cond[3], v);
    if(a == -1 && b == -1) {
        int &c = v[cond[0] - 'a'], &d = v[cond[3] - 'a'];
        for(int i = 0;i < 4;++i) {
            c = x[i]; d = y[i];
            if(c == d) ret += solve(exp1, v);
            else ret += solve(exp2, v);
        }
    }
    else if(a == -1) {
        v[cond[0] - 'a'] = b;
        ret += solve(exp1, v);
        v[cond[0] - 'a'] = !b;
        ret += solve(exp2, v);
    }
    else if(b == -1) {
        v[cond[3] - 'a'] = a;
        ret += solve(exp1, v);
        v[cond[3] - 'a'] = !a;
        ret += solve(exp2, v);
    }
    else if(a == b) ret = solve(exp1, v);
    else ret = solve(exp2, v);
    
    return ret;
}


int main(){
    //fastio
    int n;
    scanf("%d", &n);
    string in;
    cin >> in;
    printf("%d", solve(in, vector<int>(n, -1)));
}
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

struct EU {
    int gcd;
    int s;
    int t;
};

EU xGCD(int a, int b) {
    vector<int> s, t, r, q;
    s = { 1,0 };
    t = { 0,1 };
    r = { a,b };
 
    while(1){
        int r2 = r[r.size() - 2];
        int r1 = r[r.size() - 1];
        q.push_back(r2 / r1);
        r.push_back(r2 % r1);
        
        if (r[r.size() - 1] == 0)
            break;
 
        int s2 = s[s.size() - 2];
        int s1 = s[s.size() - 1];
 
        int t2 = t[t.size() - 2];
        int t1 = t[t.size() - 1];
        
        int q1 = q[q.size() - 1];
        s.push_back(s2 - s1 * q1);
        t.push_back(t2 - t1 * q1);
    }
    EU ret={r[r.size() - 2], s[s.size() - 1], t[t.size() - 1]};
    return ret;
}

int main(){
    fastio
    int a, b, c;
    cin>>a>>b>>c;
    if(c==0) cout<<"0 0";
    else if(!c%a) cout<<c/a<<" 0";
    else if(!c%b) cout<<"0 "<<c/b;
    EU xgcd=xGCD(a, b);
    if(c==xgcd.gcd) cout<<xgcd.s<<" "<<xgcd.t;
}
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
#define X first
#define Y second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mid ((l+r)>>1)

using namespace std;
typedef long long ll;
const int dx[] ={ -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[] ={ 0, 1, 0, -1, 1, 1, -1, -1 };

string ans="";

void f(vector<vector<int>> v, int x, int y, int n) {
    queue<pair<pii, int>> q;
    q.push({ { x, y, }, n });
    while (!q.empty()) {
        int tn=q.front().Y;
        int tx=q.front().X.X;
        int ty=q.front().X.Y;
        q.pop();
        if (tn==1) {
            ans+="0"+to_string(v[tx][ty]);
            continue;
        }
        bool a, b;
        a=b=true;
        for (int i=tx; i<tx+tn; i++) {
            for (int j=ty; j<ty+tn; j++) {
                if (v[i][j]) a=false;
                else b=false;
            }
        }
        if (a) ans+="00";
        else if (b) ans+="01";
        else {
            ans+="1";
            int nn=tn/2;
            q.push({ { tx, ty, }, nn });
            q.push({ { tx, ty+nn }, nn });
            q.push({ { tx+nn, ty }, nn });
            q.push({ { tx+nn, ty+nn }, nn });
        }
    }
    return;
}

string binstring_to_hexstring(string &s) {
    string rest="";
    for (int i=1; 1; i++) {
        if (sz(s)<=pow(2, i)) {
            int tmp=(int)pow(2, i)-sz(s);
            for (int j=0; j<tmp; j++) {
                string tmps="0"+s;
                s=tmps;
            }
            break;
        }
    }
    for (int i=0; i<sz(s); i+=4) {
        string tmp=s.substr(i, 4);
        if (!tmp.compare("0000"))
        {
            rest = rest + "0";
        }
        else if (!tmp.compare("0001"))
        {
            rest = rest + "1";
        }
        else if (!tmp.compare("0010"))
        {
            rest = rest + "2";
        }
        else if (!tmp.compare("0011"))
        {
            rest = rest + "3";
        }
        else if (!tmp.compare("0100"))
        {
            rest = rest + "4";
        }
        else if (!tmp.compare("0101"))
        {
            rest = rest + "5";
        }
        else if (!tmp.compare("0110"))
        {
            rest = rest + "6";
        }
        else if (!tmp.compare("0111"))
        {
            rest = rest + "7";
        }
        else if (!tmp.compare("1000"))
        {
            rest = rest + "8";
        }
        else if (!tmp.compare("1001"))
        {
            rest = rest + "9";
        }
        else if (!tmp.compare("1010"))
        {
            rest = rest + "A";
        }
        else if (!tmp.compare("1011"))
        {
            rest = rest + "B";
        }
        else if (!tmp.compare("1100"))
        {
            rest = rest + "C";
        }
        else if (!tmp.compare("1101"))
        {
            rest = rest + "D";
        }
        else if (!tmp.compare("1110"))
        {
            rest = rest + "E";
        }
        else if (!tmp.compare("1111"))
        {
            rest = rest + "F";
        }
    }
    return rest;
}

int main() {
    fastio;
    int t;
    cin>>t;
    for (;t--;) {
        int n;
        cin>>n;
        vector<vector<int>> v(n, vector<int>(n));
        for (auto &i:v) for (auto &j:i) cin>>j;
        ans="";
        f(v, 0, 0, n);
        ans=binstring_to_hexstring(ans);
        for (;1;) {
            if (ans[0]=='0') ans=ans.substr(1, sz(ans)-1);
            else break;
        }
        if (sz(ans)) cout<<ans<<"\n";
        else cout<<"0\n";
    }
}
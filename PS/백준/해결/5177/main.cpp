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

void ltrim(string &s){s.erase(s.begin(), find_if(all(s), [](int ch){return !isspace(ch);}));}
void rtrim(string &s){s.erase(find_if(s.rbegin(), s.rend(), [](int ch){return !isspace(ch);}).base(), s.end());}
void trim(string &s){rtrim(s),ltrim(s);}
void lowwercase(string &s){transform(s.begin(), s.end(), s.begin(),[](unsigned char c){ return std::tolower(c);});}
void replace(string &s){for(auto &i:s){if(i=='{'||i=='[') i='(';if(i=='}'||i==']') i=')';if(i==';') i=',';}}
void del_space(string &s){
    int idx=-1, n=sz(s);
    bool mk=false;
    for(int i=0; i<n; i++){
        if(mk&&s[i]==' ') s[i]='*';
        else if(s[i]==' ') mk=true;
        else if(mk) mk=false;
    }
    s.erase(remove(all(s), '*'), s.end());
    n=sz(s);
    for(int i=0; i<n; i++){
        if(s[i]=='('||s[i]==')'||s[i]==','||s[i]=='.'||s[i]==':'){
            if(i>0&&s[i-1]==' ') s[i-1]='*';
            if(i<n-1&&s[i+1]==' ') s[i+1]='*';
        }
    }
    s.erase(remove(all(s), '*'), s.end());
}

int main(){
    fastio
    int n;
    cin>>n;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    for(int T=1; T<=n; T++){
        string a, b;
        getline(cin, a);
        getline(cin, b);
        trim(a), trim(b);
        lowwercase(a), lowwercase(b);
        replace(a), replace(b);
        del_space(a), del_space(b);
        if(a==b) cout<<"Data Set "<<T<<": equal\n\n";
        else cout<<"Data Set "<<T<<": not equal\n\n";
    }
}
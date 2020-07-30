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
#define mid ((l+r)>>1)

using namespace std;
typedef long long ll;
const int dx[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

void left(string &s){
    char tmp=s[sz(s)-1];
    for(int i=sz(s); i>0; i--){
        s[i]=s[i-1];
    }
    s[0]=tmp;
}
void right(string &s){
    char tmp=s[0];
    for(int i=0; i<sz(s)-1; i++){
        s[i]=s[i+1];
    }
    s[sz(s)-1]=tmp;
}

int main(){
    fastio
    vector<string> v;
    v.pb(" ");
    for(int i=0; i<4; i++){
        string tmps;
        cin>>tmps;
        v.pb(tmps);
    }
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int a, b;
        cin>>a>>b;
        if(a==1){
            bool flag=true;
            char c=v[1][2];
            if(b==1){
                left(v[1]);
                b=-1;
            }
            else{
                right(v[1]);
                b=1;
            }
            if(c==v[2][6]) flag=false;
            else{
                c=v[2][2];
                if(b==1){
                    left(v[2]);
                    b=-1;
                }
                else{
                    right(v[2]);
                    b=1;
                }
            }
            if(flag){
                if(c==v[3][6]) flag=false;
                else{
                    c=v[3][2];
                    if(b==1){
                        left(v[3]);
                        b=-1;
                    }
                    else{
                        right(v[3]);
                        b=1;
                    }
                }
            }
            if(flag){
                if(c==v[4][6]) flag=false;
                else{
                    if(b==1){
                        left(v[4]);
                        b=-1;
                    }
                    else{
                        right(v[4]);
                        b=1;
                    }
                }
            }
        }
        else if(a==2){
            char l=v[2][6];
            char r=v[2][2];
            if(b==1){
                left(v[2]);
                b=-1;
            }
            else{
                right(v[2]);
                b=1;
            }
            if(l!=v[1][2]){
                if(b==1) left(v[1]);
                else right(v[1]);
            }
            bool flag=true;
            if(r==v[3][6]) flag=false;
            else{
                r=v[3][2];
                if(b==1){
                    left(v[3]);
                    b=-1;
                }
                else{
                    right(v[3]);
                    b=1;
                }
            }
            if(flag){
                if(r==v[4][6]) flag=false;
                else{
                    if(b==1){
                        left(v[4]);
                        b=-1;
                    }
                    else{
                        right(v[4]);
                        b=1;
                    }
                }
            }
        }
        else if(a==3){
            char l=v[3][6];
            char r=v[3][2];
            if(b==1){
                left(v[3]);
                b=-1;
            }
            else{
                right(v[3]);
                b=1;
            }
            if(r!=v[4][6]){
                if(b==1) left(v[4]);
                else right(v[4]);
            }
            bool flag=true;
            if(l==v[2][2]) flag=false;
            else{
                l=v[2][6];
                if(b==1){
                    left(v[2]);
                    b=-1;
                }
                else{
                    right(v[2]);
                    b=1;
                }
            }
            if(flag){
                if(l==v[1][2]) flag=false;
                else{
                    if(b==1){
                        left(v[1]);
                        b=-1;
                    }
                    else{
                        right(v[1]);
                        b=1;
                    }
                }
            }
        }
        else{
            bool flag=true;
            char c=v[4][6];
            if(b==1){
                left(v[4]);
                b=-1;
            }
            else{
                right(v[4]);
                b=1;
            }
            if(c==v[3][2]) flag=false;
            else{
                c=v[3][6];
                if(b==1){
                    left(v[3]);
                    b=-1;
                }
                else{
                    right(v[3]);
                    b=1;
                }
            }
            if(flag){
                if(c==v[2][2]) flag=false;
                else{
                    c=v[2][6];
                    if(b==1){
                        left(v[2]);
                        b=-1;
                    }
                    else{
                        right(v[2]);
                        b=1;
                    }
                }
            }
            if(flag){
                if(c==v[1][2]) flag=false;
                else{
                    if(b==1){
                        left(v[1]);
                        b=-1;
                    }
                    else{
                        right(v[1]);
                        b=1;
                    }
                }
            }
        }
    }
    int ans=0;
    if(v[1][0]=='1') ans++;
    if(v[2][0]=='1') ans+=2;
    if(v[3][0]=='1') ans+=4;
    if(v[4][0]=='1') ans+=8;
    cout<<ans;
}
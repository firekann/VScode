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

int main(){
    int n;
    cin>>n;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    for(int T=1; T<=n; T++){
        string a, b;
        getline(cin, a);
        getline(cin, b);
        int alen=sz(a);
        int blen=sz(b);
        int cnt=0;
        bool flag=true;
        for(int i=0; i<alen; i++){
            if(a[i]==' '){
                if(b[cnt]!=' '){
                    cout<<a[i]<<"===\n";
                    cout<<"Data Set "<<T<<": not equal\n\n";
                    flag=false;
                    break;
                }
                for(;b[cnt]==' '; cnt++);
                for(;a[i]==' ';i++);
                i--;
            }
            else if(a[i]=='('||a[i]=='{'||a[i]=='['){
                if(b[cnt]=='('||b[cnt]=='{'||b[cnt]=='[') cnt++;
                else{
                    cout<<a[i]<<"===\n";
                    cout<<"Data Set "<<T<<": not equal\n\n";
                    flag=false;
                    break;
                }
            }
            else if(a[i]==')'||a[i]=='}'||a[i]==']'){
                if(b[cnt]==')'||b[cnt]=='}'||b[cnt]==']') cnt++;
                else{
                    cout<<a[i]<<"===\n";
                    cout<<"Data Set "<<T<<": not equal\n\n";
                    flag=false;
                    break;
                }
            }
            else if(a[i]==','||a[i]==';'){
                if(b[cnt]==','||b[cnt]==';') cnt++;
                else{
                    cout<<a[i]<<"===\n";
                    cout<<"Data Set "<<T<<": not equal\n\n";
                    flag=false;
                    break;
                }
            }
            else{
                a[i]=toupper(a[i]);
                b[cnt]=toupper(b[cnt]);
                if(a[i]==b[cnt]) cnt++;
                else{
                    cout<<a[i]<<"===\n";
                    cout<<"Data Set "<<T<<": not equal\n\n";
                    flag=false;
                    break;
                }
            }
        }
        if(flag) cout<<"Data Set "<<T<<": equal\n\n";
    }
}
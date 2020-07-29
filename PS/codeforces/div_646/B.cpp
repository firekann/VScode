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

int main(){
    fastio
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        if(s.length()<3){
            cout<<"0\n";
            continue;
        }
        int cnto,  cnte;
        cnto=cnte=0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='0') cnte++;
            else cnto++;
        }
        char lc0='0', lc1='1';
        int lv0=0, lv1=0;
        int cnt0=0, cnt1=0;;
        for(int i=0; i<s.length(); i++){
            if(s[i]!=lc0) cnt0++;
            else{
                lv0+=cnt0;
                cnt0=0;
            }
            if(s[i]!=lc1) cnt1++;
            else{
                lv1+=cnt1;
                cnt1=0;
            }
        }
        char rc0='0', rc1='1';
        int rv0=0, rv1=0;
        cnt0=cnt1=0;
        for(int i=s.length()-1; i>=0; i--){
            if(s[i]!=rc0) cnt0++;
            else{
                rv0+=cnt0;
                cnt0=0;
            }
            if(s[i]!=rc1) cnt1++;
            else{
                rv1+=cnt1;
                cnt1=0;
            }
        }
        //cout<<lv0<<" "<<lv1<<" "<<rv0<<" "<<rv1<<"\n";
        cout<<min(min(cnto, cnte), min(min(lv0, lv1), min(rv0, rv1)))<<"\n";
    }
}
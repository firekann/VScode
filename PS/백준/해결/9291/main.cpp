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
    string S="123456789";
    for(int T=1; T<=t; T++){
        int arr[9][9];
        for(int i=0; i<9; i++) for(int j=0; j<9; j++) cin>>arr[i][j];
        bool flag=true;
        for(int i=0; i<9; i++){
            string s1="", s2="";
            for(int j=0; j<9; j++){
                s1+=to_string(arr[i][j]);
                s2+=to_string(arr[j][i]);
            }
            sort(all(s1)), sort(all(s2));
            if(s1!=S||s2!=S){
                flag=false;
                break;
            }
        }
        if(flag){
            for(int I=0; I<9; I+=3){
                for(int J=0; J<9; J+=3){
                    string s="";
                    for(int i=I; i<I+3; i++){
                        for(int j=J; j<J+3; j++){
                            s+=to_string(arr[i][j]);
                        }
                    }
                    sort(all(s));
                    if(s!=S){
                        flag=false;
                        break;
                    }
                }
                if(!flag) break;
            }
        }
        cout<<"Case "<<T<<": ";
        if(flag) cout<<"CORRECT\n";
        else cout<<"INCORRECT\n";
    }
}
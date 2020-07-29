#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

using namespace std;
typedef long long ll;
const int dx[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

int a['a'+1];

int main(){
    int n;
    cin>>n;
    vector<char> v;
    while(n--){
        string s;
        cin>>s;
        a[s[0]-'a']++;
    }
    bool flag=true;
    for(int i=0; i<='a'; i++)
        if(a[i]>4){
            printf("%c", i+'a');
            flag=false;
        }
    if(flag) cout<<"PREDAJA";
}
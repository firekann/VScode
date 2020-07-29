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
    char s[20];
    gets(s);
    map<char, int> mp;
    for(int i=0; i<10; i++) mp[s[i]]=i;
    char str[20];
    gets(str);
    for(int i=0; i<strlen(str); i++){
        if(str[i]==' ') cout<<" ";
        else cout<<mp[str[i]];
    }
}
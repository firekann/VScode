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

map<int, pair<int, int>> point;

int main(){
    fastio
    point[0]={3, 1};
    point[1]={0, 0};
    point[2]={0, 1};
    point[3]={0, 2};
    point[4]={1, 0};
    point[5]={1, 1};
    point[6]={1, 2};
    point[7]={2, 0};
    point[8]={2, 1};
    point[9]={2, 2};
    int h, m;
    char tmps[5];
    cin>>tmps;
    h=(tmps[0]-'0')*10+(tmps[1]-'0');
    m=(tmps[3]-'0')*10+(tmps[4]-'0');
    int mint=1e9;
    string ans;
    for(int i=h; i<100; i+=24){
        for(int j=m; j<100; j+=60){
            int a[4];
            a[0]=i/10, a[1]=i%10, a[2]=j/10, a[3]=j%10;
            int tmpx=point[a[0]].X;
            int tmpy=point[a[0]].Y;
            int tmpv=0;
            for(int k=1; k<4; k++){
                tmpv+=abs(tmpx-point[a[k]].X)+abs(tmpy-point[a[k]].Y);
                tmpx=point[a[k]].X;
                tmpy=point[a[k]].Y;
            }
            if(mint>tmpv){
                mint=tmpv;
                ans="";
                for(int k=0; k<4; k++){
                    ans+=to_string(a[k]);
                    if(k==1) ans+=":";
                }
            }
        }
    }
    cout<<ans;
}
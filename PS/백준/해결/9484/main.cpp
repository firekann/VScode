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
    while(1){
        int n;
        cin>>n;
        if(!n) break;
        vector<pair<double, double>> v(n);
        for(int i=0; i<n; i++) cin>>v[i].X>>v[i].Y;
        double maxs=-1;
        double mins=1e9;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    double S;
                    S=abs((v[i].X*v[j].Y+v[j].X*v[k].Y+v[k].X*v[i].Y)-(v[i].X*v[k].Y+v[k].X*v[j].Y+v[j].X*v[i].Y))/2;
                    maxs=max(maxs, S);
                    mins=min(mins, S);
                }
            }
        }
        cout<<fixed;
        cout.precision(1);
        cout<<mins<<" "<<maxs<<"\n";
    }
}
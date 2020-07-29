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

typedef complex<double> cd;
typedef vector<cd> vcd;
const double pi=acos(-1);

void fft(vcd &f, cd w){
    int n=sz(f);
    if(n==1) return;
    vcd even(n/2), odd(n/2);
    for(int i=0; i<n; i++){
        if(i%2) odd[i/2]=f[i];
        else even[i/2]=f[i];
    }
    fft(even, w*w), fft(odd, w*w);
    cd wt(1, 0);
    for(int i=0; i<n/2; i++){
        f[i]=even[i]+wt*odd[i];
        f[i+n/2]=even[i]-wt*odd[i];
        wt*=w;
    }
}

vcd multi(vcd a, vcd b){
    int n=1;
    while(n<=sz(a)||n<=sz(b)) n*=2;
    n*=2;;
    a.resize(n), b.resize(n);
    vcd c(n);
    cd w(cos(2*pi/n), sin(2*pi/n));
    fft(a, w), fft(b, w);
    for(int i=0; i<n; i++) c[i]=a[i]*b[i];
    fft(c, cd(w.real(), -w.imag()));
    for(int i=0; i<n; i++) c[i]/=cd(n, 0), c[i]=cd(round(c[i].real()), round(c[i].imag()));
    return c;
}

int main(){
    fastio
    string ta, tb;
    cin>>ta>>tb;
    reverse(all(ta));
    reverse(all(tb));
    vcd a, b, c;
    for(auto i:ta) a.push_back(cd(i-'0', 0));
    for(auto i:tb) b.push_back(cd(i-'0', 0));
    c=multi(a, b);
    vector<int> v(sz(c)*2);
    for(int i=0; i<sz(c); i++) v[i]=(int)round(c[i].real());
    v.push_back(0);
    for(int i=0; i<sz(v)-1; i++){
        if(v[i]<0){
            int tmp=(abs(v[i])+9)/10;
            v[i+1]-=tmp;
            v[i]+=tmp*10;
        }
        else{
            v[i+1]+=v[i]/10;
            v[i]%=10;
        }
    }
    while(sz(v)>1&&!v.back()) v.pop_back();
    reverse(all(v));
    for(auto i:v) cout<<i;
}
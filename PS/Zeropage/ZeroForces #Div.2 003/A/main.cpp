#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr)
#define X first
#define Y second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mid ((l + r) >> 1)

using namespace std;
typedef long long ll;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

typedef complex<double> cpx;

void fft(vector<cpx> &a, bool ck)
{
    int n = sz(a);
    for (int i = 1, j = 0; i < n; i++)
    {
        int bit = n / 2;
        for (; bit <= j; bit /= 2)
            j -= bit;
        j += bit;
        if (i < j)
            swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len *= 2)
    {
        double ang = 2 * M_PI / len;
        if (ck)
            ang = -ang;
        cpx w(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len)
        {
            cpx wp(1, 0);
            for (int j = 0; j < len / 2; j++)
            {
                cpx u = a[i + j], v = a[i + j + len / 2] * wp;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                wp *= w;
            }
        }
    }
    if (ck)
        for (int i = 0; i < n; i++)
            a[i] /= n;
}

vector<int> mul(vector<int> &a, vector<int> &b)
{
    vector<cpx> aa(all(a)), bb(all(b));
    int n = 1;
    while (n < sz(a) || n < sz(b))
        n *= 2;
    aa.resize(n), bb.resize(n);
    fft(aa, 0), fft(bb, 0);
    for (int i = 0; i < n; i++)
        aa[i] *= bb[i];
    fft(aa, 1);
    vector<int> tmp(n);
    for (int i = 0; i < n; i++)
        tmp[i] = int(aa[i].real() + (aa[i].real() > 0 ? 0.5 : -0.5));
    return tmp;
}

int ans[202020];

int main()
{
    fastio;
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    string sa, sb;
    cin >> sa >> sb;
    int tmp[200];
    tmp['R'] = 0, tmp['P'] = 1, tmp['S'] = 2;
    for (int i = 0; i < n; i++)
        a[i] = (tmp[sa[i]] + 1) % 3;
    for (int i = 0; i < m; i++)
        b[i] = tmp[sb[i]];
    for (int i = 0; i < 3; i++)
    {
        vector<int> u(n + m), v(m);
        for (int j = 0; j < n; j++)
            u[j] = a[j] == i;
        for (int j = 0; j < m; j++)
            v[j] = b[m - j - 1] == i;
        vector<int> tmp = mul(u, v);
        for (int j = 0; j < n + m; j++)
            ans[j] += tmp[j];
    }
    cout << *max_element(ans + m - 2, ans + n + m);
}
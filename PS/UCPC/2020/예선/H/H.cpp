#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;
typedef long long ll;
const int dx[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

int main(){
    fastio
    int n;
	scanf("%d", &n);
	
	std::vector<int> h(n);
	for (int i = 0; i < n; i++) scanf("%d", &h[i]);

	int cnt = 0, hap = 0;
	for (int i = 0; i < n; i++)
	{
		cnt += (h[i] / 2);
		hap += h[i];
	}

	if (!(hap % 3) && cnt * 3 >= hap) printf("YES\n");
	else printf("NO\n");
	return 0;
}
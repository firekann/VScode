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
	std::vector<std::vector<int>> rel(n+1, std::vector<int>(0));
	for (int i = 1; i <= n; i++)
	{
		while(true)
		{
			int t;
			scanf("%d", &t);
			if (t == 0) break;

			rel[i].push_back(t);
		}
	}

	int m;
	scanf("%d", &m);
	
	std::queue<std::pair<int,int>> que;
	std::vector<int> visit(n + 1, -1);
	for (int i = 0; i < m; i++)
	{
		int t;
		scanf("%d", &t);

		que.push({ t,0 });
		visit[t] = 0;
	}

	int all_time = 0;
	std::vector<int> per;
	while (!que.empty())
	{
		int idx = que.front().first;
		int time = que.front().second;
		que.pop();

		if (all_time != time)
		{
			all_time++;
			for (int x : per) visit[x] = all_time;
			per.clear();
		}

		for (int x : rel[idx])
		{
			if (visit[x] != -1) continue;
			
			int cnt = 0;
			for (int y : rel[x])
			{
				if (visit[y] != -1) cnt++;
			}
			
			if (cnt * 2 >= rel[x].size())
			{
				que.push({ x,time + 1 });
				per.push_back(x);
			}
		}
	}

	for (int i = 1; i <= n; i++) printf("%d ", visit[i]);
	return 0;
}
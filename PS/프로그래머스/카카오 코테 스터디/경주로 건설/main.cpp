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

typedef struct info{
    int x, y, dir, cost;
} info;

int n;
vector<int> ans;

/*
(0, 1) R -> 1
(1, 0) D -> 2
(-1, 0) U -> 0
(0, -1) L -> 3
*/

int cal_cost(int curdir, int nextdir, int cost){
    if(curdir%2&&nextdir%2) return cost+100;
    if(!(curdir%2)&&!(nextdir%2)) return cost+100;
    if(curdir%2&&!(nextdir%2)) return cost+600;
    if(!(curdir%2)&&nextdir%2) return cost+600; 
}

void bfs(int x, int y, int dir, int cost, vector<vector<int>> board){
    deque<info> qinfo;
    qinfo.push_front({x, y, dir, cost});
    vector<vector<int>> visit=board;
    visit[x][y]=1;
    for(;!qinfo.empty();){
        info tmpinfo=qinfo.back();
        x=tmpinfo.x, y=tmpinfo.y, cost=tmpinfo.cost, dir=tmpinfo.dir;
        qinfo.pop_back();
        if(x==n-1&&y==n-1){
            ans.push_back(cost);
            continue;
        }
        for(int i=0; i<4; i++){
            int tmpx=x+dx[i];
            int tmpy=y+dy[i];
            int tmpcost=cal_cost(dir, i, cost);
            if(tmpx<0||tmpy<0||tmpx>=n||tmpy>=n) continue;
            if(!board[tmpx][tmpy]){
                if(!visit[tmpx][tmpy]||visit[tmpx][tmpy]>tmpcost){
                    visit[tmpx][tmpy]=tmpcost;
                    qinfo.push_front({tmpx, tmpy, i, tmpcost});
                }
            }
        }

    }
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    n=(int)board[0].size();
    bfs(0, 0, 1, 0, board);
    bfs(0, 0, 2, 0, board);
    sort(all(ans));
    answer=ans[0];
    return answer;
}

int main(){
    fastio
    int N;
    cin>>N;
    vector<vector<int>> vv(N);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int tmp;
            cin>>tmp;
            vv[i].push_back(tmp);
        }
    }
    cout<<solution(vv);   
}
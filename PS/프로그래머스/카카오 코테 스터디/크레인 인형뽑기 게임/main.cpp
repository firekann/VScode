#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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

using namespace std;
typedef long long ll;
const int dx[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

int solution(vector<vector<int>> board, vector<int> moves)
{
    int answer = 0;
    int st_size = sz(board);
    stack<int> st_board[st_size];
    for (int i = 0; i < st_size; i++) {
        for (int j = st_size - 1; j >= 0; j--) {
            if (board[j][i] == 0)
                break;
            st_board[i].push(board[j][i]);
        }
    }
    stack<int> st;
    int cnt = 0;
    for (auto i : moves) {
        int tmp;
        if (!st_board[i - 1].empty()) {
            tmp = st_board[i - 1].top();
            st_board[i - 1].pop();
        } else {
            continue;
        }
        if (!st.empty()) {
            if (tmp == st.top()) {
                cnt += 2;
                st.pop();
            } else {
                st.push(tmp);
            }
        } else {
            st.push(tmp);
        }
    }
    answer = cnt;
    return answer;
}

int main()
{
    fastio;
    int n;
    cin >> n;
    vector<vector<int>> vv(n, vector<int>(n));
    for (auto& i : vv)
        for (auto& j : i)
            cin >> j;
    int m;
    cin >> m;
    vector<int> v(m);
    for (auto& i : v)
        cin >> i;
    cout << solution(vv, v);
}
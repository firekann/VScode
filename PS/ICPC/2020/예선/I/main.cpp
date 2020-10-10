#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> sss(2 * n);
    for (int i = 0; i < 2 * n; i++)
        cin >> sss[i];
    sort(sss.begin(), sss.end());
    int res = 202020;
    for (int i = 0, j = 2 * n - 1; i < j; i++, j--)
        res = std::min(res, sss[i] + sss[j]);
    cout << res;
    return 0;
}
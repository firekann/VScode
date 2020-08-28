#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Answer;

int main(int argc, char **argv)
{
    int T, test_case;
    cin >> T;
    for (test_case = 0; test_case < T; test_case++)
    {
        Answer = 0;
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        vector<int> aa(k), bb(k);
        for (auto &i : a)
            cin >> i;
        for (auto &i : b)
            cin >> i;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for (int i = 0; i < k; i++)
        {
            aa[i] = a[i];
            bb[i] = b[i];
        }
        reverse(bb.begin(), bb.end());
        int ans = 0;
        for (int i = 0; i < k; i++)
        {
            int tmp = aa[i] + bb[i];
            ans = max(ans, tmp);
        }
        Answer = ans;
        cout << "Case #" << test_case + 1 << "\n";
        cout << Answer << "\n";
    }

    return 0;
}
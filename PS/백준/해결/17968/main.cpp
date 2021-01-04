#include <bits/stdc++.h>

int a[1010];

int main()
{
    int n;
    std::cin >> n;
    a[0] = 1, a[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1;; j++) {
            a[i] = j;
            bool flag = true;
            for (int k = 1; 2 * k <= i; k++) {
                if (a[i] - a[i - k] == a[i - k] - a[i - 2 * k]) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                break;
        }
    }
    std::cout << a[n];
    return 0;
}
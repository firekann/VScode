#include <bits/stdc++.h>

using namespace std;

int uf[500010];
int a[1000010], b[1000010];

int find(int x) {
    if(uf[x] == x) return x;
    return uf[x] = find(uf[x]);
}

void merge(int x, int y) {
    x = find(x); y = find(y);

    uf[x] = y;
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0;i < m;++i) {
        scanf("%d %d", &a[i], &b[i]);
    }

    for(int i = 0;i < n;++i) uf[i] = i;

    for(int i = 0;i < m;++i) {
        //printf("%d %d\n", find(a[i]), find(b[i]));
        if(find(a[i]) != find(b[i])) merge(a[i], b[i]);
        else {
            printf("%d\n", i + 1);
            return 0;
        }
    }
    //for(int i = 0;i < n;++i) printf("%d ", uf[i]);

    printf("0");

    return 0;
}
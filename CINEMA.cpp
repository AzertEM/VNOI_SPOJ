#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int m, n, k;
int a[N * N], res[N][N];

void next(int &x, int &y) {
    if (x % 2 == 0) {
        if (y == 1) x++;
        else y--;
        return;
    }

    if (y == n) x++;
    else y++;
}

int main() {
    scanf("%d%d", &m, &n);
    scanf("%d", &k);

    int x = 1, y = 1;
    for (int i = 1; i <= k; i++) {
        int tmp;
        scanf("%d", &tmp);
        while (tmp--) {
            res[x][y] = i;
            next(x, y);
        }
    }

    for (int i = 1; i <= m; i++, puts(""))
    for (int j = 1; j <= n; j++)
        printf("%d ", res[i][j]);
}
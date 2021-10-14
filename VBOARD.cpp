#include <bits/stdc++.h>
using namespace std;

const int N = 550;
int n;
int a[N][N][2], f[N][N][2];

int sum(int u, int v, int x, int y, int color) {
    return f[x][y][color] - f[x][v - 1][color] - f[u - 1][y][color] + f[u - 1][v - 1][color];
}

int main() {
    scanf("%d", &n);
    bool color = false;
    for (int i = 1; i <= n; i++) {
        color = (i % 2);
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j][color]);
            f[i][j][color] = f[i][j - 1][color] + f[i - 1][j][color] - f[i - 1][j - 1][color] + a[i][j][color];
            color = !color;
            f[i][j][color] = f[i][j - 1][color] + f[i - 1][j][color] - f[i - 1][j - 1][color];
        }
    }
    
    int q;
    scanf("%d", &q);
    while (q--) {
        int x, y, u, v;
        scanf("%d%d%d%d", &x, &y, &u, &v);
        printf("%d\n", abs(sum(x, y, u, v, 1) - sum(x, y, u, v, 0)));
    }
}
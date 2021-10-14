#include <bits/stdc++.h>
#define long long long
using namespace std;

const long oo = 1e15;
const int N = 1e3 + 2;
int m, n, Q;
long c[N][N], f[N][N][2];

int main() {
    scanf("%d", &Q);
    while (Q--) {
        scanf("%d%d", &m, &n);
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                scanf("%lld", &c[i][j]);
            }
        }

        for (int i = 0; i <= m; i++)
            for (int j = 0; j <= n; j++) 
                f[i][j][0] = f[i][j][1] = oo;
                
        for (int i = 1; i <= m; i++) f[i][0][0] = 0;
        for (int j = 1; j <= n; j++) f[0][j][1] = 0;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                f[i][j][0] = min(f[i - 1][j][0], f[i - 1][j][1] + c[i][j]);
                f[i][j][1] = min(f[i][j - 1][1], f[i][j - 1][0] + c[i][j]);
            }
        }

        long res = min(f[m][n][0], f[m][n][1]);
        printf("%lld\n", res);
    }
}
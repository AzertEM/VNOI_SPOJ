#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX / 2;
int n;
int c[20][20], f[20][(1 << 16) + 1];

//Debug
void printBit(int stt) {
    for (int i = 0; i < n; i++) {
        printf("%d", (stt >> i) & 1);
    }
}
//EndDebug

int dp(int u, int stt) {
    if (f[u][stt] != -1) return f[u][stt];

    int best = INF;
    for (int v = 1; v <= n; v++) {
        if (v != u && ((stt >> (v - 1)) & 1) == 1) {
            int oldStt = stt - (1 << (u - 1));
            best = min(best, dp(v,oldStt) + c[v][u]);
        }
    }

    if (f[u][stt] == -1) f[u][stt] = best;
    return best;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) 
    for (int j = 1; j <= n; j++) 
        scanf("%d", &c[i][j]);

    memset(f, -1, sizeof(f));

    for (int i = 1; i <= n; i++)
        f[i][1 << (i - 1)] = 0;

    int res = INF;
    for (int i = 1; i <= n; i++) res = min(res, dp(i, (1 << n) - 1));
    printf("%d", res);
}
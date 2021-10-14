#include <bits/stdc++.h>
using namespace std;

int avail[8] = {9, 10, 5, 8, 4, 2, 1, 0};

const int INF = 1e9 + 7;
const int N = 1e4 + 4;
int n;
int a[5][N], f[N][20];

int dp(int i, int stt) {
    if (i > n) return 0;
    if (f[i][stt] != -INF) return f[i][stt];

    int ret = -INF;
    for (int id = 0; id < 8; id++) {
        int newStt = avail[id];
        if (stt & newStt) continue;

        int c = 0;
        for (int bit = 0; bit < 4; bit++) c += a[bit + 1][i] * ((newStt >> bit) & 1);

        ret = max(ret, dp(i + 1, newStt) + c);
    }

    return f[i][stt] = ret;
}

int main() {
    int Max = -INF;
    scanf("%d", &n);
    for (int i = 1; i <= 4; i++)
    for (int j = 1; j <= n; j++) 
        scanf("%d", &a[i][j]), Max = max(Max, a[i][j]);

    for (int i = 1; i <= n; i++)
    for (int j = 0; j < 16; j++) 
        f[i][j] = -INF;
    
    int res = dp(1, 0);
    if (res == 0) printf("%d", Max);
    else printf("%d", res);
    // printf("%d\n", dp(1, 0));
}
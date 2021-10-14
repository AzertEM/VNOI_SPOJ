#include <bits/stdc++.h>
using namespace std;

const int N = 1050;
int n, q;
int bit[N][N];

void update(int x, int y, int val) {
    for (int i = x; i <= n; i += i & (-i))
    for (int j = y; j <= n; j += j & (-j)) 
        bit[i][j] += val; 
}

int get(int x, int y) {
    int ret = 0;
    for (int i = x; i >= 1; i -= i & (-i))
    for (int j = y; j >= 1; j -= j & (-j))
        ret += bit[i][j];
    return ret;
}

int main() {
    scanf("%d%d", &q, &n);
    while (scanf("%d", &q) && q != 3) {
        if (q == 1) {
            int x, y, val;
            scanf("%d%d%d", &x, &y, &val);
            x++, y++;
            update(x, y, val);
        }
        if (q == 2) {
            int x, y, u, v;
            scanf("%d%d%d%d", &u, &v, &x, &y);
            u++, v++, x++, y++;
            int res = get(x, y) - get(x, v - 1) - get(u - 1, y) + get(u - 1, v - 1);
            printf("%d\n", res);
        }
    }
}
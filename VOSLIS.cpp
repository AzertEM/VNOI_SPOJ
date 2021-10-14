#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

int main() {
    int t, m, n, i, j, a[1505], b[1505], c[1505];
    ii cur, prev;
    memset(c, 0, sizeof(c));
    scanf("%d%d", &m, &n);
    for (i = 0; i < m; ++i) scanf("%d", &a[i]);
    for (i = 0; i < n; ++i) scanf("%d", &b[i]);
    for (i = 0; i < m; ++i) {
        cur = ii(0, 0);
        for (j = 0; j < n; ++j) {
            prev = cur;
            if (2 * b[j] <= a[i])
                cur.first = max(cur.first, c[j]);
            if (a[i] == b[j])
                c[j] = max(c[j], prev.first + 1);
        }
    }
    cur.first = 0;
    for (i = 0; i < n; ++i)
        cur.first = max(cur.first, c[i]);
    printf("%d", cur.first);
}
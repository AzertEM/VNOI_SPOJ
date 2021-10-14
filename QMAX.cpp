#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 1;
int n, m, q, k;
int a[N], ST[N * 4];

int update(int id, int l, int r) {
    if (l == r) {
        ST[id] = a[l];
        return ST[id];
    }

    int mid = (l + r) / 2;
    ST[id] = max(update(id * 2, l, mid), update(id * 2 + 1, mid + 1, r));
    return ST[id];
}

//Return the Max value in [u..v]
int maxLR(int id, int l, int r, int u, int v) {
    if (v < l || r < u) return -1;
    
    if (u <= l && r <= v) return ST[id];

    int mid = (l + r) / 2;
    return max(maxLR(id * 2, l, mid, u, v), maxLR(id * 2 + 1, mid + 1, r, u, v)); 
}

int main() {
    int L, R;
    
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &L, &R, &k);
        a[L] += k, a[R + 1] -= k;
    }
    for (int i = 1; i <= n; i++) a[i] += a[i - 1];

    update(1, 1, n);

    scanf("%d", &q);
    while (q--) {
        scanf("%d%d", &L, &R);
        printf("%d\n", maxLR(1, 1, n, L, R));
    }
}
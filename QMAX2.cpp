#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;
const int N = 5e4 + 4;
int n, m, q, L, R, value;

struct Node {
    int lazy;
    int val;
} node[N * 4];

void down(int id) {
    int t = node[id].lazy;
    node[id * 2].lazy += t;
    node[id * 2].val += t;

    node[id * 2 + 1].lazy += t;
    node[id * 2 + 1].val += t;

    node[id].lazy = 0;
}

void update(int id, int l, int r, int u, int v, int val) {
    if (v < l || r < u) return;

    if (u <= l && r <= v) {
        node[id].val += val;
        node[id].lazy += val;
        return;
    }

    int mid = (l + r) / 2;

    down(id);

    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);

    node[id].val = max(node[id * 2].val, node[id * 2 + 1].val);
}

int get(int id, int l, int r, int u, int v) {
    if (v < l || r < u) return -INF;

    if (u <= l && r <= v) {
        return node[id].val;
    }

    down(id);

    int mid = (l + r) / 2;

    return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

int main() {
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d", &q);

        if (q == 0) {
            scanf("%d%d%d", &L, &R, &value);
            update(1, 1, n, L, R, value);
        }
        else {
            scanf("%d%d", &L, &R);
            printf("%d\n", get(1, 1, n, L, R));
        }
    }
}
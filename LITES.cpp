#include <bits/stdc++.h>
using namespace std;

int const INF = INT_MAX;
int const N = 1e5 + 4;
int n, m;

struct Node {
    int val;
    int lazy;
} node[N * 4];

void down(int id, int l, int r) {
    if (node[id].lazy) {
        int mid = (l + r) / 2;

        node[id * 2].val = mid - l + 1 - node[id * 2].val;
        node[id * 2].lazy = (node[id * 2].lazy + 1) % 2;

        node[id * 2 + 1].val = r - mid - node[id * 2 + 1].val;
        node[id * 2 + 1].lazy = (node[id * 2 + 1].lazy + 1) % 2;
    }
    node[id].lazy = 0;
}

void update(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return;

    if (u <= l && r <= v) {
        node[id].val = r - l + 1 - node[id].val;
        node[id].lazy = (node[id].lazy + 1) % 2;
        return;
    }

    down(id, l, r);

    int mid = (l + r) / 2;
    update(id * 2, l, mid, u, v);
    update(id * 2 + 1, mid + 1, r, u, v);

    node[id].val = node[id * 2].val + node[id * 2 + 1].val;
}

int get(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return 0;

    if (u <= l && r <= v) return node[id].val;

    down(id, l, r);

    int mid = (l + r) / 2;
    
    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}

int main() {
    scanf("%d%d", &n, &m);

    int q, x, y;
    while (m--) {
        scanf("%d%d%d", &q, &x, &y);
        if (q == 0) update(1, 1, n, x, y);
        else printf("%d\n", get(1, 1, n, x, y));
    }
}
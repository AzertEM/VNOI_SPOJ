#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;
const int N = 1e5 + 4;
int n, m;
int S[N];
char brack[N];

struct Node {
    int sum;
    int min;
    int lazy;
} node[N * 4];

int value(char ch) {
    return (ch == '(')? 1 : -1;
}

void down(int id) {
    int t = node[id].lazy;
    node[id * 2].min += t;
    node[id * 2].lazy += t;

    node[id * 2 + 1].min += t;
    node[id * 2 + 1].lazy += t;

    node[id].lazy = 0;
}

void INIT(int id, int l, int r) {
    if (l == r) {
        node[id].sum = value(brack[l]);
        node[id].min = S[l];
        return;
    }

    int mid = (l + r) / 2;
    INIT(id * 2, l, mid);
    INIT(id * 2 + 1, mid + 1, r);

    node[id].min = min(node[id * 2].min, node[id * 2 + 1].min);
    node[id].sum = node[id * 2].sum + node[id * 2 + 1].sum;
}

void update(int id, int l, int r, int u, int v, int val) {
    if (l > v || r < u) return;

    if (u <= l && r <= v) {
        node[id].min += val;
        node[id].lazy += val;
        return;
    }

    down(id);

    int mid = (l + r) / 2;
    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);

    node[id].min = min(node[id * 2].min, node[id * 2 + 1].min);
}

void update_sum(int id, int l, int r, int x, int val) {
    if (x < l || r < x) return;

    node[id].sum += val;

    if (l == r) return;

    int mid = (l + r) / 2;
    update_sum(id * 2, l, mid, x, val);
    update_sum(id * 2 + 1, mid + 1, r, x, val);
}

int get_min(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return INF;

    if (u <= l && r <= v) return node[id].min;

    down(id);

    int mid = (l + r) / 2;
    return min(get_min(id * 2, l, mid, u, v), get_min(id * 2 + 1, mid + 1, r, u, v));
}

int get_sum(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return 0;

    if (u <= l && r <= v) return node[id].sum;

    int mid = (l + r) / 2;
    return get_sum(id * 2, l, mid, u, v) + get_sum(id * 2 + 1, mid + 1, r, u, v);
}

bool check(int l, int r) {
    if (get_sum(1, 1, n, l, r) != 0) return false;
    if (get_min(1, 1, n, l, r) - get_sum(1, 1, n, 1, l - 1) < 0) return false;
    return true; 
}

int main() {
    scanf("%d%d", &n, &m);
    scanf("%s", brack + 1);
    for (int i = 1; i <= n; i++) S[i] = value(brack[i]) + S[i - 1];

    INIT(1, 1, n);

    int q, x, y;
    string ch;
    while (m--) {
        scanf("%d", &q);

        if (q == 0) {
            scanf("%d", &x);
            cin >> ch;
            update(1, 1, n, x, n, value(ch[0]) - value(brack[x]));
            update_sum(1, 1, n, x, value(ch[0]) - value(brack[x]));
            brack[x] = ch[0];
        }
        else {
            scanf("%d%d", &x, &y);
            printf("%d", check(x, y));
        }
    }
}
#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int c, n, res;
int w[N];

void choose(int a, int cost) {
    if (cost > c) return;

    if (a > n) {
        res = max(res, cost);
        return;
    }

    for (int i = 0; i < 2; i++) choose(a + 1, cost + w[a] * i);
}

int main() {
    scanf("%d%d", &c, &n);
    for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
    choose(1, 0);
    printf("%d", res);
}
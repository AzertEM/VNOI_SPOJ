#include <bits/stdc++.h>
using namespace std;

const int N = 6e4 + 6;
int n;
int a[N], node[N];

void update(int pos, int val) {
    for (int i = pos; i < N; i += i & (-i))
        node[i] += val;
}

long long get(int pos) {
    long long ret = 0;
    for (int i = pos; i >= 1; i -= i & (-i))
        ret += node[i];
    return ret;
}

int main() {
    long long res = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        res += i - 1 - get(a[i]);
        update(a[i], 1);
    }

    printf("%lld", res);
}
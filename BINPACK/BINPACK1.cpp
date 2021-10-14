#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int L, n;
int res = N, box = 2;
int a[N], w[2];

void choose(int index) {
    if (index > n) {
        // cout << "GOT HERE " << res << " " << box << "\n";
        res = min(res, box);
        return;
    }

    for (int i = 0; i < 2; i++) {
        if (a[index] + w[i] <= L) {
            w[i] += a[index];
            choose(index + 1);
            w[i] -= a[index];
        }
        else {
            int temp = w[i];
            w[i] = a[index], box++;
            choose(index + 1);
            w[i] = temp, box--;
        }
    }
}

int main() {
    scanf("%d%d", &L, &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    choose(1);
    printf("%d", res);
}
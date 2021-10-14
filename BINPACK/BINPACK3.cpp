#include <bits/stdc++.h>
using namespace std;

int L, n;

namespace sub1 {
    const int N = 1e6 + 5;
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
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        choose(1);
        printf("%d", res);
        return 0;
    }
}

namespace sub2 {
    const int N = 1e6 + 5;
    int res = N, box = 2;
    int a[N], w[2];

    int main() {
        int res = 0;
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]), res += a[i];
        printf("%d", res / L + (res % L != 0));
        return 0;
    }
}

namespace sub3{
    const int N = 1e4 + 5;
    const int oo = 1e9;
    int a[N], f[N][31][31];

    int main() {
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

        for (int i = 0; i <= n; i++)
        for (int w1 = 0; w1 <= L; w1++)
        for (int w2 = 0; w2 <= L; w2++)
            f[i][w1][w2] = oo;
    
        f[0][0][0] = 0;
        for (int i = 1; i <= n; i++)
        for (int w1 = 0; w1 <= L; w1++)
        for (int w2 = 0; w2 <= L; w2++) {
            if (w1 - a[i] == 0)
                for (int t = L - a[i] + 1; t <= L; t++)  f[i][w1][w2] = min(f[i][w1][w2], f[i - 1][t][w2] + 1);
            if (w2 - a[i] == 0)
                for (int t = L - a[i] + 1; t <= L; t++)  f[i][w1][w2] = min(f[i][w1][w2], f[i - 1][w1][t] + 1);
            if (w1 - a[i] >= 0) f[i][w1][w2] = min(f[i][w1][w2], f[i - 1][w1 - a[i]][w2]);
            if (w2 - a[i] >= 0) f[i][w1][w2] = min(f[i][w1][w2], f[i - 1][w1][w2 - a[i]]);
        }
    
    int res = oo;
    for (int w1 = 0; w1 <= L; w1++) 
    for (int w2 = 0; w2 <= L; w2++)
        res = min(res, f[n][w1][w2]);
    
    printf("%d", res + 2);
    return 0;
}
}

int main() {
    scanf("%d%d", &L, &n);
    if (n <= 20) sub1::main();
    else if (L == 100) sub2::main();
    else sub3::main();
}
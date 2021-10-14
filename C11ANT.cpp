#include <bits/stdc++.h>
using namespace std;

const double EP = 1e-15;
const int N = 1e5 + 5;
const int LIM = 1e4;
int n;
long long a[N], v[N];

double calculate(double time) {
    double l = a[1] + v[1] * time;
    double r = a[1] + v[1] * time;
    for (int i = 2; i <= n; i++) {˜
        l = min(l, a[i] + v[i] * time);
        r = max(r, a[i] + v[i] * time);
    }
    return (r - l) / 2;
}

int main() {
    // freopen("_debug.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%lld", &v[i]);
    if (n == 2) {
        cout << "0.000\n";
        return 0;
    }
    double l = 0, r = 1e9 + 1;
    double m1, m2, res1, res2;
    int k = 0;
    while (l <= r - EP && k <= LIM) {
        // cout << l << " " << r << "\n";
        m1 = l + (r - l) / 3.0;
        m2 = m1 + (r - l) / 3.0;
        // cout << m1 << " " << m2 << "\n";
        res1 = calculate(m1);
        res2 = calculate(m2);
        // cout << res1 << " " << res2 << "\n";
        if (res1 <= res2 + EP) r = m2;
        else l = m1;
        k++;
    }

    printf("%.3f\n", min(calculate(l), calculate(r)));
}
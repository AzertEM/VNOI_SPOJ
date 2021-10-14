#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;
const int N = 2003;
int n;
int a[N], pre[N], f[N];
bool arr[N][N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) 
        if (a[j] == a[i]) pre[j] = i;

    for (int i = 1; i <= n; i++) {
        arr[i][i] = true;
        int mn = a[i], mx = a[i];
        int gcd = 0;
        for (int j = i + 1; j <= n; j++) {
            if (pre[j] >= i) break;
            gcd = __gcd(gcd, abs(a[j] - a[i]));
            mn = min(mn, a[j]);
            mx = max(mx, a[j]);
            if ((mx - mn) / gcd == j - i) arr[i][j] = true;
        }
    }

    for (int i = 1; i <= n; i++) {
        f[i] = INF;
        for (int j = i; j >= 1; j--)
            if (arr[j][i]) f[i] = min(f[i], f[j - 1] + 1);
    }
    printf("%d\n", f[n]);
}
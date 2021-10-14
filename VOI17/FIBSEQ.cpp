#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 6;
int n, k, MOD;
int f[N], s[N], cnt[N];
long long t;

class matrix {
public:
    int val[5][5];

    matrix operator * (matrix const &b) {
        matrix res;
        for (int i = 1; i <= 2; i++)
        for (int j = 1; j <= 2; j++) {
            res.val[i][j] = 0;
            for (int k = 1; k <= 2; k++) 
                res.val[i][j] = (res.val[i][j] + (1LL * val[i][k] * b.val[k][j]) % MOD) % MOD;
        }
        return res;
    }

    void print() {
        for (int i = 1; i <= 2; i++, puts(""))
        for (int j = 1; j <= 2; j++)
            cout << val[i][j] << " ";
    }
}a , b;

matrix po(matrix a, long long p) {
    if (p == 1) return a;
    matrix res = po(a, p / 2);
    if (p % 2 == 0) return res * res;
    return res * res * a;
}

int main() {
    // freopen("fibseq.inp", "r", stdin);
    // freopen("fibseq.out", "w", stdout);
    int query;
    scanf("%d", &query);
    while (query--) {
        memset(cnt, 0, sizeof(cnt));
        scanf("%d%lld%d", &n, &t, &k);
        MOD = k;
        //fibo(i..i + n - 1)
        a.val[1][1] = 1; b.val[1][1] = 0;
        a.val[1][2] = 1; b.val[1][2] = 1; 
        a.val[2][1] = 0; b.val[2][1] = 1;
        a.val[2][2] = 0; b.val[2][2] = 1;
        if (t > 1) a = a * po(b, t - 1);
        for (long long i = t; i < n + t; i++) {
            f[i - t + 1] = a.val[1][1];
            a = a * b;
        }
        
        // for (int i = 1; i <= n; i++) cout << f[i] << " ";
        // cout << endl;
        long long q = 0, l = 0, r = 0;
        for (int i = 1; i <= n; i++) {
            s[i] = (s[i - 1] + f[i]) % MOD;
            // cout << s[i] << " ";
            if (cnt[s[i]] != 0) {
                // cout << i << " " << cnt[s[i]] << "\n";
                l = t + cnt[s[i]];
                r = i + t - 1;
                q = r - l + 1;
                break;
                // cout << q << " " << l << " " << r << "\n";
            }
            else cnt[s[i]] = i;
        }
        // cout << endl << "\n";

        printf("%lld ", q);
        if (q == 0) continue;
        for (long long i = l; i <= r; i++) printf("%lld ", i);
        puts("");
    }
}
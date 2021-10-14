#include <bits/stdc++.h>
using namespace std;

int MOD;
long long n;

class matrix {
public:
    int val[6][6];

    matrix() {
        for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
            val[i][j] = 0;
    }

    matrix operator *(matrix const &b) {
        matrix res;
        for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++) {
            res.val[i][j] = 0;
            for (int k = 1; k <= 3; k++) 
                res.val[i][j] = (res.val[i][j] + (1LL * val[i][k] * b.val[k][j]) % MOD) % MOD;
        }
        return res;
    }

    void print() {
        for (int i = 1; i <= 3; i++, puts(""))
        for (int j = 1; j <= 3; j++)
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
    scanf("%lld%d", &n, &MOD);
    //f[i] = f[i - 1] + f[i - 2] + f[i - 3]
    //f[i - 3]..f[i - 2]..f[i - 1]..f[i]
    //f[i - 2]..f[i - 1]..f[i]..f[i + 1]
    a.val[1][1] = 1; a.val[1][2] = 2;
    a.val[1][3] = 4;

    b.val[2][1] = 1; b.val[3][2] = 1;
    b.val[1][3] = 1; b.val[2][3] = 1;
    b.val[3][3] = 1;

    if (n <= 3) {
        printf("%d", a.val[1][n]);
        return 0;
    }
    a = a * po(b, n - 3);
    printf("%d", a.val[1][3]);
}
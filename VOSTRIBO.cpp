#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e15 + 7;

long long mul(long long a, long long b) {
    if (b == 0) return 0;
    if (b == 1) return a;
    long long res = mul(a, b / 2);
    if (b % 2 == 0) 
        return (res + res) % MOD;
    return ((res + res) % MOD + a) % MOD;
}

class matrix {
public:
    long long val[6][6];

    matrix operator *(matrix const &b) {
        matrix res;
        for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++) {
            res.val[i][j] = 0;
            for (int k = 1; k <= 4; k++) 
                res.val[i][j] = (res.val[i][j] + (1LL * mul(val[i][k], b.val[k][j]) % MOD)) % MOD;
        }
        return res;
    }

    void print() {
        for (int i = 1; i <= 2; i++, puts(""))
        for (int j = 1; j <= 2; j++)
            cout << val[i][j] << " ";
    }
}a , b;

matrix po(matrix a, int p) {
    if (p == 1) return a;
    matrix res = po(a, p / 2);
    if (p % 2 == 0) return res * res;
    return res * res * a;
}

int main() {
    // a.print();
    // b.print();
    int t;
    cin >> t;
    int n;
    while (t--) {
        for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
            a.val[i][j] = 0, b.val[i][j] = 1;
        
        b.val[1][1] = b.val[1][2] = b.val[2][2] = b.val[3][1] = b.val[4][1] = b.val[4][2] = b.val[4][3] = 0;
        a.val[1][1] = 1; a.val[1][2] = 2; a.val[1][3] = 3; a.val[1][4] = 6;
        // cout << "HERE\n";
        cin >> n;
        if (n == 2) {
            cout << 3 << "\n";
            continue;
        }
        if (n == 1) {
            cout << 1 << "\n";
            continue;
        }
        if (n == 3) {
            cout << 6 << "\n";
            continue;
        }
        a = a * po(b, n - 3);
        // cout << "EHE\n";
        cout << a.val[1][4] << "\n";
    }
}
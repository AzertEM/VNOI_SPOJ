#include <bits/stdc++.h>
using namespace std;

const int MOD = 111539786;
int d[4][4] = {{1, 1}, {1, 0}};

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
        a.val[1][1] = 1; b.val[1][1] = 0;
        a.val[1][2] = 1; b.val[1][2] = 1; 
        a.val[2][1] = 0; b.val[2][1] = 1;
        a.val[2][2] = 0; b.val[2][2] = 1;
        cin >> n;
        a = a * po(b, n);
        cout << a.val[1][1] << "\n";
    }
}
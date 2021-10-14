#include <bits/stdc++.h>
using namespace std;

const int MOD = 10;
int n;
string s;

class matrix {
public:
    int row, col;
    vector <vector<int>> val;
    matrix() {};
    matrix(int _row, int _col) {
        row = _row, col = _col;
        val.resize(row + 1);
        for (int i = 1; i <= row; i++) {
            val[i].resize(col + 1);
            for (int j = 1; j <= col; j++)
                val[i][j] = 0;
        }
    }

    matrix operator *(matrix const &b) {
        matrix res(row, b.col);
        for (int i = 1; i <= row; i++)
        for (int j = 1; j <= b.col; j++) {
            res.val[i][j] = 0;
            for (int k = 1; k <= col; k++)
                res.val[i][j] = (res.val[i][j] + (1LL * val[i][k] * b.val[k][j]) % MOD) % MOD;
        }
        return res;
    }

    bool operator == (matrix const &b) {
        if (row != b.row || col != b.col) return false;
        for (int i = 1; i <= row; i++)
        for (int j = 1; j <= col; j++)
            if (val[i][j] != b.val[i][j]) return false;
        return true;
    }

    // bool operator != (matrix const &b) {
    //     return !( == );
    // }
    
    void print() {
        cout << row << " " << col << "\n";
        for (int i = 1; i <= row; i++, puts(""))
        for (int j = 1; j <= col; j++)
            cout << val[i][j] << " ";
    }

    void printRes() {
        long long res = 0;
        for (int i = 1; i <= col; i++) res += val[1][i], res %= MOD;
        printf("%lld\n", res);
    }
};

int main() {
    int q;
    ios::sync_with_stdio(false);
    // scanf("%d", &q);
    cin >> q;
    while (q--) {
        cin >> n;
        matrix a(n, n), b(n, n), c(n, n);
        // return 0;
        for (int i = 1; i <= n; i++) {
            cin >> s;
            for (int j = 0; j < n; j++) a.val[i][j + 1] = s[j] - '0';
        }
        for (int i = 1; i <= n; i++) {
            cin >> s;
            for (int j = 0; j < n; j++) b.val[i][j + 1] = s[j] - '0';
        }
        for (int i = 1; i <= n; i++) {
            cin >> s;
            for (int j = 0; j < n; j++) c.val[i][j + 1] = s[j] - '0';
        }
        matrix v1(1, n), v2(1, n);
        for (int i = 0; i < n; i++) {
            v1.val[1][i + 1] = (2 * i) % 10;
            v2.val[1][i + 1] = (2 * i + 1) % 10;
        }
        // cout << (a == b) << "\n";
        if (((v2 * a) * b) == v2 * c) puts("YES");
        else puts("NO");
    }
}
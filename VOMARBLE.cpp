#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef pair <long long, long long> ii;
typedef pair <long long, ii> iii;

const int MOD = 1e9 + 7;
long long n, m, k;
vector <iii> query;
map <char, int> id;

class matrix {
public:
    int row, col;
    long long val[64][64];
    matrix() {};
    matrix(int _row, int _col) {
        row = _row, col = _col;
        for (int i = 1; i <= row; i++)
        for (int j = 1; j <= col; j++)
            val[i][j] = 0;
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
}a(1, 62) , b(62, 62);

matrix po(matrix a, int p) {
    if (p == 1) return a;
    matrix res = po(a, p / 2);
    if (p % 2 == 0) return res * res;
    return res * res * a;
}

matrix p[66];

//a * (b ^ n)
matrix mul(matrix a, long long n) {
    if (n == 0) return a;
    matrix res = a;
    for (int i = 60; i >= 0; i--) {
        if (n - (1LL << i) >= 0){
            res = res * p[i], n -= 1LL << i;
        }
    }
    return res;
}

int main() {
    int tata = 0;
    for (char i = '0'; i <= '9'; i++) id[i] = ++tata;
    for (char i = 'a'; i <= 'z'; i++) id[i] = ++tata;
    for (char i = 'A'; i <= 'Z'; i++) id[i] = ++tata;

    p[0] = matrix(62, 62);
    for (int i = 1; i <= 62; p[0].val[i][i] = 1, i++) 
    for (int j = 1; j <= 62; j++)
        b.val[i][j] = 1;
    for (int i = 1; i <= 62; i++) a.val[1][i] = 1;

    scanf("%lld%lld%lld", &n, &m, &k);
    for (int i = 1; i <= m; i++) {
        string s1, s2;
        char x, y;
        cin >> s1 >> s2;
        x = s1[0], y = s2[0];
        b.val[id[x]][id[y]] = b.val[id[y]][id[x]] = 0;
    }
    for (int i = 1; i <= k; i++) {
        long long t, pos;
        string s1;
        char x;
        cin >> t >> pos >> s1;
        x = s1[0];
        query.push_back(iii(pos, ii(t, id[x])));
    }
    sort(query.begin(), query.end());
    
    p[0] = b;
    long long cur = 1;
    for (int i = 1; i <= 60; i++) p[i] = p[i - 1] * p[i - 1];
    for (int i = 0; i < query.size(); i++) {
        matrix tmp = b;
        long long pos = query[i].fi - cur + 1, t = query[i].se.fi;
        int c = query[i].se.se;

        a = mul(a, pos - 1);
        if (t == 1) {
            for (int i = 1; i <= 62; i++) {
                if (i == c) continue;
                a.val[1][i] = 0;
            }
        }
        if (t == 0) {
            a.val[1][c] = 0;
        }

        cur = query[i].fi;
    }

    a = mul(a, n - cur);
    a.printRes();
}
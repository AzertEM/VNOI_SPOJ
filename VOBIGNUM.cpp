#include <bits/stdc++.h>
using namespace std;

const int N = 1100;
const int MOD = 999999929;
int n, q;
long long a[N];

long long val(string s) {
    long long ret = 0;
    bool neg = false;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '-') {neg = true; continue;}
        ret = (ret * 10 + s[i] - '0') % MOD;
    }

    if (neg) ret = ret * -1 + MOD;
    return ret;
}

long long calc(int x1, int y1, char c1) {
    if (c1 == '-') return (a[x1] - a[y1]) % MOD + MOD;
    if (c1 == '*') return a[x1] * a[y1];
    return a[x1] + a[y1];
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        string smp;
        cin >> smp;
        a[i] = val(smp);
        // cout << a[i] << "\n";
    }

    int x1, y1, x2, y2;
    char c1, c2;
    while (q--) {
        cin >> x1 >> y1;
        cin >> c1;
        cin >> x2 >> y2;
        cin >> c2;

        long long res1 = calc(x1, y1, c1) % MOD, res2 = calc(x2, y2, c2) % MOD;
        if (res1 == res2) puts("YES");
        else puts("NO");
    }
}
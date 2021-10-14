#include <bits/stdc++.h>
#define long long long
using namespace std;

const int N = 402;
int m, n;
char s[N][N];
long h[N], L[N];

long check(int row, char x, char y, char z) {
    for (int i = 1; i <= n; i++) {
        if (s[row][i] == x || s[row][i] == y || s[row][i] == z)
            h[i] = h[i] + 1;
        else h[i] = 0;
    }

    stack <int> st;
    st.push(0);
    for (int i = 1; i <= n; i++) {
        while (st.size() > 1 && h[st.top()] >= h[i]) st.pop();
        L[i] = st.top();
        st.push(i);
    }

    long f[N], ret = 0;
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; i++) {
        f[i] = h[i] * (i - L[i]) + f[L[i]];
        ret += f[i];
    }

    return ret;
}

long calculate(char x, char y, char z) {
    long ret = 0;
    memset(h, 0, sizeof(h));

    for (int i = 1; i <= m; i++) {
        ret += check(i, x, y, z);
    }

    return ret;
}

int main() {
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++) {
        scanf("%s", s[i] + 1);
    }
    long res = 0;
    for (char i = 'A'; i <= 'C'; i++) 
    for (char j = i + 1; j <= 'D'; j++)
    for (char k = j + 1; k <= 'E'; k++) {
        res += calculate(i, j, k) - calculate(i, i, j) - calculate(j, j, k)
        - calculate(k, k, i) + calculate(i, i, i) + calculate(j, j, j) + calculate(k, k, k);
    }
    printf("%lld", res);
}
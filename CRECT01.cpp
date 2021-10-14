#include <bits/stdc++.h>
#define long long long
using namespace std;

const int N = 1001;
long m, n, res;
long h[N], L[N], R[N + 1], f[N];
char a[N][N];

long check(int row) {
    for (int i = 1; i <= n; i++) h[i] = (h[i] + 1) * (a[row][i] - '0');
    stack <int> st;

    st.push(0);
    for (int i = 1; i <= n; i++) {
        while (st.size() > 1 && h[st.top()] >= h[i]) st.pop();
        L[i] = st.top();
        st.push(i);
    }

    long ret = 0;
    for (int i = 1; i <= n; i++) {
        f[i] = h[i] * (i - L[i]) + f[L[i]];
        ret += f[i];
    }

    return ret;
}

int main() {
    scanf("%lld%lld", &m, &n);
    for (int i = 1; i <= m; i++) 
        scanf("%s", a[i] + 1);
    
    for (int row = 1; row <= m; row++) {
        long t = check(row);
        res += t;
    }
    
    printf("%lld", res);
}
#include <bits/stdc++.h>
using namespace std;

const int N = 1001;
int m, n, res;
int a[N][N], h[N], L[N], R[N];

int check(int row) {
    for (int i = 1; i <= n; i++) h[i] = (h[i] + 1) * a[row][i];
    stack <int> st;

    st.push(0);
    for (int i = 1; i <= n; i++) {
        while (st.size() > 1 && h[st.top()] >= h[i]) st.pop();
        L[i] = st.top();
        st.push(i);
    }

    while (st.size()) st.pop();

    st.push(n + 1);
    for (int i = n; i >= 1; i--) {
        while (st.size() > 1 && h[st.top()] >= h[i]) st.pop();
        R[i] = st.top();
        st.push(i);
    }

    int ret = 0;
    for (int i = 1; i <= n; i++) ret = max(ret, (R[i] - L[i] - 1) * h[i]);

    return ret;
}

int main() {
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
        scanf("%d", &a[i][j]);
    
    for (int row = 1; row <= m; row++) res = max(res, check(row));
    
    printf("%d", res);
}
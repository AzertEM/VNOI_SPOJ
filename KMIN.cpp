#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int N = 5e4 + 5;
int m, n, k;
int a[N], b[N];
set <ii> st;

int main() {
    scanf("%d%d%d", &m, &n, &k);
    for (int i = 1; i <= m; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);

    sort(a + 1, a + m + 1);
    sort(b + 1, b + n + 1);

    priority_queue <iii, vector<iii>, greater<iii>> pq;
    pq.push(iii(a[1] + b[1], ii(1, 1)));
    while (k--) {
        int res = pq.top().first;
        int i = pq.top().second.first, j = pq.top().second.second;
        pq.pop();

        if (st.find(ii(i, j)) != st.end()) {k++; continue;}
        st.insert(ii(i, j));
        printf("%d\n", res);
        if (i < m) pq.push(iii(a[i + 1] + b[j], ii(i + 1, j)));
        if (j < n) pq.push(iii(a[i] + b[j + 1], ii(i, j + 1)));
    }
}
#include <bits/stdc++.h>
using namespace std;

const int N = 220;
int n, k;
int dsu[N], a[N][N];

int find(int i) {
    return (dsu[i] == i)? i : (dsu[i] = find(dsu[i]));
}

void join(int i, int j) {
    dsu[find(i)] = find(j);
}

bool check(int s) {
    for (int i = 1; i <= n; i++) dsu[i] = i;

    for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
        if (a[i][j] < s) join(i, j);
    
    set<int> st;
    for (int i = 1; i <= n; i++) 
            st.insert(find(i));

    if (st.size() < k) return false;
    return true;
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) scanf("%d", &a[i][j]);

    int l = 0, r = 33000;
    while (r - l > 1) {
        int mid = (r + l) / 2;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }

    if (check(r)) printf("%d\n", r);
    else printf("%d\n", l);
}
#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int INF = 1e9 + 7;
const int N = 1e5 + 5;
int n;
int node[N][3];
iii a[N];


void update(int pos, int val, int id) {
    for (int i = pos; i <= n; i += i & (-i))
        node[i][id] = min(val, node[i][id]);
}

int get(int pos, int id) {
    int ret = INF;
    for (int i = pos; i >= 1; i -= i & (-i))
        ret = min(node[i][id], ret);
    return ret;
}

int main() {
    scanf("%d", &n);
    int tmp;
    for (int i = 1; i <= n; i++) scanf("%d", &tmp), a[i].fi = tmp;
    for (int i = 1; i <= n; i++) scanf("%d", &tmp), a[i].se.fi = tmp;
    for (int i = 1; i <= n; i++) scanf("%d", &tmp), a[i].se.se = tmp;

    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) node[i][0] = node[i][1] = INF;
    for (int i = 1; i <= n; i++) {
        update(i, a[i].se.fi, 0);
        update(i, a[i].se.se, 1);
    }
    for (int i = 1; i <= n; i++) cout << a[i].fi << " "; cout << endl;
    for (int i = 1; i <= n; i++) cout << a[i].se.fi << " "; cout << endl;
    for (int i = 1; i <= n; i++) cout << a[i].se.se << " "; cout << endl;

    int res = 1;
    for (int i = 2; i <= n; i++) {
        if (get(i - 1, 0) > a[i].se.fi || get(i - 1, 1) > a[i].se.se) res++, cout << i << " ";
    }
    cout << "\n";
    printf("%d\n", res);
}
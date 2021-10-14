#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int n = 8;
int k;
long long res;

int idx(int i, int j) {
    return (i - 1) * n + j;
}

vector <ii> c, d;
int reward[70];
bool knight[70][70], bishop[70][70], queen[70][70], rook[70][70];

int main() {
    scanf("%d", &k);
    for (int i = 1; i <= k; i++) {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        c.push_back(ii(x, y));
        reward[idx(x, y)] = w;
    }

    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
        if (reward[idx(i, j)] == 0) d.push_back(ii(i, j));

    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
    for (int x = 1; x <= n; x++)
    for (int y = 1; y <= n; y++) {
        int cur = idx(i, j), reach = idx(x, y);
        rook[cur][reach] = (i == x) || (j == y);
        bishop[cur][reach] = (i - j) == (x - y) || (i + j) == (x + y);
        queen[cur][reach] = rook[cur][reach] || bishop[cur][reach];
        knight[cur][reach] = (abs(i - x) == 2 && abs(j - y) == 1) || (abs(i - x) == 1 && abs(j - y) == 2);
    }

    int lim = d.size(), sz = c.size();
    for (int i = 0; i < lim; i++)
    for (int j = 0; j < lim; j++)
    for (int k = 0; k < lim; k++)
    for (int t = 0; t < lim; t++) {
        if (i == j || i == k || i == t || j == k || j == t || k == t) continue;
        long long sum = 0;
        int Q = idx(d[i].first, d[i].second), R = idx(d[j].first, d[j].second);
        int B = idx(d[k].first, d[k].second), K = idx(d[t].first, d[t].second);
        for (int thaibao = 0; thaibao < sz; thaibao++) {
            int target = idx(c[thaibao].first, c[thaibao].second);
            if (rook[R][target] || queen[Q][target] || bishop[B][target] || knight[K][target]) sum += reward[target];
        }

        res = max(res, sum);
    }

    printf("%lld", res);
}
#include <bits/stdc++.h>
using namespace std;

const int N = 1100;
int n, m, res;
int dsu[N];
vector <pair<int, pair<int, int>>> edge;

int find(int i) {
    return (dsu[i] == i)? i : dsu[i] = dsu[find(dsu[i])];
}

void merge(int i, int j) {
    dsu[find(i)] = find(j);
}

void kruskal() {
    int done = 0, cur = 0;
    while (done < n - 1) {
        int u = edge[cur].second.first, v = edge[cur].second.second, w = edge[cur].first;
        if (find(u) != find(v)) {
            done++;
            merge(u, v);
            res = w;
        }
        cur++;
    }
}

int main() {
    int u, v, w;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        edge.push_back(make_pair(w, make_pair(u, v)));
    }
    sort(edge.begin(), edge.end());

    for (int i = 1; i <= n; i++) dsu[i] = i;
    kruskal();

    printf("%d\n", res);
}
#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 4;
int n = 1, m = 1, cnt;
int root, children, bridge, vertex;
int low[N], num[N], parent[N];
bool articulation[N];
vector <int> adj[N];

void findArticulation(int u) {
    low[u] = num[u] = ++cnt;

    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (num[v] == 0) {
            parent[v] = u;
            if (u == root) children++;
            findArticulation(v);
            if (low[v] >= num[u]) articulation[u] = true;
            if (low[v] > num[u]) bridge++;
            low[u] = min(low[u], low[v]);
        }
        else if (v != parent[u])
            low[u] = min(low[u], num[v]);
    }
}

int main() {
    int u, v;

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (num[i] == 0) {
            root = i; children = 0;
            findArticulation(i);
            articulation[root] = (children > 1);
        }
    }

    for (int i = 1; i <= n; i++)
        if (articulation[i]) vertex++;

    printf("%d %d", vertex, bridge);
}
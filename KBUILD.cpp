#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, m, cnt, bridge;
int low[N], num[N], parent[N];
vector <int> adj[N];

void findBridge(int u) {
    low[u] = num[u] = ++cnt;

    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (num[v] == 0) {
            parent[v] = u;
            findBridge(v);
            if (low[v] > num[u]) bridge++;
            low[u] = min(low[u], low[v]);
        }
        else if (v != parent[u])
            low[u] = min(low[u], num[v]);
    }
}

int main() {
    int a, b;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    findBridge(1);

    printf("%d", bridge);
}
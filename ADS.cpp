#include <bits/stdc++.h>
using namespace std;

const int N = 10000;
int m, n, connected_component;
int head[N + 1], adj[N + 1], u[N + 1], v[N + 1];
bool visit[N + 1];

void adjlist(int n, int m) {
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &u[i], &v[i]);
        head[u[i]]++; head[v[i]]++;
    }

    for (int i = 1; i <= n + 1; i++) 
        head[i] += head[i - 1];

    for (int i = 1; i <= m; i++) {
        adj[head[u[i]]] = v[i];
        adj[head[v[i]]] = u[i];
        head[u[i]]--; head[v[i]]--;
    }
}

void DFS(int u) {
    visit[u] = true;
    for (int i = head[u] + 1; i <= head[u + 1]; i++) {
        if (!visit[adj[i]]) DFS(adj[i]);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    adjlist(n, m);
    for (int v = 1; v <= n; v++) {
        if (!visit[v]) {
            DFS(v);
            connected_component++;
        }
    }
    printf("%d", m - n + connected_component);
}
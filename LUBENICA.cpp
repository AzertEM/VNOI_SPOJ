#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9 + 7;
int n, cur_pos = 1, cur_edge = 1, cur_head = 1;
int depth[N], parent[N], head[N], pos[N], heavy[N], edge[N], idx[N], adx[N];
int nodeMi[N * 4], nodeMa[N * 4];
vector <pair <int, int> > adj[N];

int dfs(int u) {
    int size = 1;
    int max_c_size = 0;
    
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i].first;
        if (v != parent[u]) {
            parent[v] = u;
            depth[v] = depth[u] + 1;
            int c_size = dfs(v);
            size += c_size;
            if (c_size > max_c_size) {
                max_c_size = c_size;
                heavy[u] = v;
                idx[u] = i;
            }
        }
        else {
            adx[u] = i;
        }
    }
    return size;
}

void decompose(int u, int h) {
    head[u] = h, pos[u] = cur_pos++;
    if (heavy[u] != -1) {
        edge[cur_edge++] = adj[u][idx[u]].second;
        decompose(heavy[u], h);
    }
    
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i].first;
        if (v != parent[u] && v != heavy[u]) {
            edge[cur_edge++] = adj[u][i].second;
            decompose(v, v);
        }
    }
}

int updateMa(int id, int l, int r) {
    if (l == r) {
        nodeMa[id] = edge[l];
        return nodeMa[id];
    }

    int mid = (l + r) / 2;
    nodeMa[id] = max(updateMa(id * 2, l, mid), updateMa(id * 2 + 1, mid + 1, r));
    return nodeMa[id];
}

int maxLR(int id, int l, int r, int u, int v) {
    u = min(u, v);
    if (v < l || r < u) return -1;
    if (u <= l && r <= v) return nodeMa[id];
    
    int mid = (l + r) / 2;
    return max(maxLR(id * 2, l, mid, u, v), maxLR(id * 2 + 1, mid + 1, r, u, v)); 
}

int updateMi(int id, int l, int r) {
    if (l == r) {
        nodeMi[id] = edge[l];
        return nodeMi[id];
    }

    int mid = (l + r) / 2;
    nodeMi[id] = min(updateMi(id * 2, l, mid), updateMi(id * 2 + 1, mid + 1, r));
    return nodeMi[id];
}

int minLR(int id, int l, int r, int u, int v) {
    u = min(u, v);
    if (v < l || r < u) return INF;
    if (u <= l && r <= v) return nodeMi[id];

    int mid = (l + r) / 2;
    return min(minLR(id * 2, l, mid, u, v), minLR(id * 2 + 1, mid + 1, r, u, v)); 
}

void query(int u, int v) {
    int Min = INF, Max = 0;
    for (; head[u] != head[v]; v = parent[head[v]]) {
        if (depth[head[u]] > depth[head[v]]) swap (u, v);
        pair <int, int> cur = {minLR(1, 1, n - 1, pos[head[v]], pos[v] - 1), 
                               maxLR(1, 1, n - 1, pos[head[v]], pos[v] - 1)};

        Min = min(Min, cur.first);
        Max = max(Max, cur.second);

        Min = min(Min, adj[head[v]][adx[head[v]]].second);
        Max = max(Max, adj[head[v]][adx[head[v]]].second);
    }

    if (depth[u] > depth[v]) swap(u, v);
    pair <int, int> last = {INF, -1};
    if (u != v) {
        last = {minLR(1, 1, n - 1, pos[u], pos[v] - 1),
                maxLR(1, 1, n - 1, pos[u], pos[v] - 1)};
    }

    Min = min(Min, last.first);
    Max = max(Max, last.second);

    cout << Min << " " << Max << "\n";
}

int main() {
    scanf("%d", &n);
    int u, v, c;
    for (int i = 1; i < n; i++) {
        scanf("%d%d%d", &u, &v, &c);
        adj[u].push_back(make_pair(v, c));
        adj[v].push_back(make_pair(u, c));
    }

    memset(heavy, -1, sizeof(heavy));
    dfs(1);
    decompose(1, 1);

    updateMi(1, 1, n - 1);
    updateMa(1, 1, n - 1);

    int k, a, b;
    scanf("%d", &k);
    while (k--) {
        scanf("%d%d", &a, &b);
        query(a, b);
    }
}
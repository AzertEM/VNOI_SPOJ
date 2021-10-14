#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <long long, ii> iii;

const int N = 1e5 + 4;
int n, m, s, t, theta;
long long d[N];
vector <int> adj[N], idx[N], dis[N];

void dijkstra() {
    priority_queue<iii, vector <iii>, greater<iii>> pq;
    memset(d, 127, sizeof(d));
    // cout << d[2] << "\n";
    pq.push(iii(0, ii(s, 0)));
    d[s] = 0;

    while (pq.size()) {
        long long du = pq.top().first;
        int u = pq.top().second.first;
        int St = pq.top().second.second;
        pq.pop();
        if (du != d[u]) continue;
        // cout << u << "\n";

        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            int nSt = idx[u][i];
            long long uv = dis[u][i];
            if (St) uv += St * theta + nSt;
            if (d[v] > du + uv) {
                d[v] = du + uv;
                pq.push(iii(d[v], ii(v, nSt)));
            }
        }
    }
}

int main() {
    freopen("METRO.inp", "r", stdin);
    freopen("METRO.out", "w", stdout);
    scanf("%d%d%d%d%d", &n, &m, &s, &t, &theta);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        adj[u].push_back(v);
        idx[u].push_back(i);
        dis[u].push_back(w);
    }

    dijkstra();

    if (d[t] == d[0]) puts("-1");
    else printf("%lld\n", d[t]);
}
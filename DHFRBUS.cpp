#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <long long, ii> iii;

const long long INF = 1e15 + 7;
const int N = 1e5 + 5;
int n, m, k, s, t;
long long d[N][7];
vector <int> adj[N], dis[N];

void dijkstra(int s) {
    priority_queue <iii, vector<iii>, greater<iii>> pq;
    long long u, du, uv, v;

    for (int i = 1; i <= n; i++)
    for (int j = 0; j <= k; j++)
        d[i][j] = INF;
    pq.push(iii(0, ii(s, k)));
    d[s][k] = 0;

    while (pq.size()) {
        u = pq.top().second.first;
        du = pq.top().first;
        int ti = pq.top().second.second;
        pq.pop();
        if (d[u][ti] != du) continue;

        for (int i = 0; i < adj[u].size(); i++) {
            v = adj[u][i];
            uv = dis[u][i];
            if (d[v][ti] > du + uv) {
                d[v][ti] = du + uv;
                pq.push(iii(d[v][ti], ii(v, ti)));
            }
            if (t == 0) continue;
            if (d[v][ti - 1] > du) {
                d[v][ti - 1] = du;
                pq.push(iii(d[v][ti - 1], ii(v, ti - 1)));
            }
        }
    }
}

int main() {
    scanf("%d%d%d%d%d", &n, &m, &k, &s, &t);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        adj[u].push_back(v), adj[v].push_back(u);
        dis[u].push_back(w), dis[v].push_back(w); 
    }

    dijkstra(s);

    printf("%lld\n", d[t][0]);
}
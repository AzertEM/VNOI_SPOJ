#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int INF = INT_MAX;
const int N = 5e3 + 5;
int n, m;
int d[N];
long long w[N];
vector <pair <int, int> > adj[N];

void addEdge(int u, int v, int l) {
    adj[u].push_back(make_pair(v, l));
}

void dijkstra(int start) {
    priority_queue <ii, vector<ii>, greater<ii> > pq;
    int u, du, tmp;

    pq.push(make_pair(0, start));
    for (int i = 1; i <= n; i++) d[i] = INF;
    d[start] = 0, w[start] = 1;

    while (!pq.empty()) {
        u = pq.top().second;
        du = pq.top().first;
        pq.pop();
        if (du != d[u]) continue;
        
        tmp = adj[u].size();
        for (int i = 0; i < tmp; i++) {
            int v = adj[u][i].first;

            if (d[v] > du + adj[u][i].second) {
                d[v] = du + adj[u][i].second;
                w[v] = w[u];
                pq.push(make_pair(d[v], v));
            }
            else if (d[v] == du + adj[u][i].second) w[v] += w[u];
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int k, u, v, l;
        scanf("%d%d%d%d", &k, &u, &v, &l);
        if (k == 1) addEdge(u, v, l);
        else {
            addEdge(u, v, l);
            addEdge(v, u, l);
        }
    }

    dijkstra(1);

    printf("%d %lld", d[n], w[n]);
}
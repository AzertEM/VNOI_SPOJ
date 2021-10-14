#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int INF = 1e9 + 7;
const int N = 5e4 + 5;
int n, m;
int d1[N], d2[N];
long long w1[N], w2[N];
vector <pair <int, int> > adj[N];

void addEdge(int u, int v, int l) {
    adj[u].push_back(make_pair(v, l));
}

void dijkstra(int start, int d[], long long w[]) {
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
    // return 0;
    for (int i = 1; i <= m; i++) {
        int u, v, l;
        scanf("%d%d%d", &u, &v, &l);
        // addEdge(u, v, l);
        // else {
            addEdge(u, v, l);
            addEdge(v, u, l);
        // }
    }

    dijkstra(1, d1, w1);
    dijkstra(n, d2, w2);

    vector <int> ans;
    for (int i = 2; i < n; i++) {
        if (d1[i] + d2[i] != d1[n]) {
            ans.push_back(i);
        }
        else if (w1[i] * w2[i] < w1[n]) ans.push_back(i);
    }

    printf("%d\n", (int)ans.size());
    for (int i: ans) printf("%d\n", i);

    // printf("%d %lld", d[n], w[n]);
}
#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e10;
const int oo = 1000111000;
typedef pair<int, int> ii;

vector<ii> a[2309];
vector <int> adj[2309];
int d[2309], c[1100][1100];
int n, m, t, k, cmin = oo;
int ans[3000];
long long dp[1100][110], cnt[1100][110];

void dijkstra() {
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (int i = 1; i <= n; i++)
        d[i] = oo;
    d[t] = 0;
    pq.push(ii(0, t));

    while (pq.size()) {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
        if (du != d[u])
            continue;

        for (int i = 0; i < a[u].size(); i++) {
            int v = a[u][i].first;
            int uv = a[u][i].second;
            if (d[v] > du + uv) {
                d[v] = du + uv;
                pq.push(ii(d[v], v));
            }
        }
    }
}

long long f(int u, int x) {
    if (cnt[u][x] != -1) return cnt[u][x];

    long long ret = 0;
    for (int ve: adj[u]) {
        int v = ve;
        if (x + d[u] - d[v] >= c[u][v])
            ret += f(v, x + d[u] - d[v] - c[u][v]);
    }

    // cout << u << " " << x << " " << ret << "\n";
    return cnt[u][x] = min(INF, ret);
}

long long ff(int u, int x) {
    if (x < 0) return 0;
    if (dp[u][x] != -1) return dp[u][x];

    return dp[u][x] = min(INF, ff(u, x - 1) + f(u, x));
}

int main() {
    int p, q, m, w;
    scanf("%d%d%d%d", &n, &m, &t, &k);
    while (m--) {
        scanf("%d%d%d", &p, &q, &w);
        a[q].push_back(ii(p, w));
        adj[p].push_back(q);
        c[p][q] = w;
        cmin = min(cmin, w);
    }

    for (int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end());
    dijkstra();
    memset(cnt, -1, sizeof(cnt));
    memset(dp, -1, sizeof(dp));
    cnt[t][0] = 1;

    int x = cmin;
    ans[1] = 1;
    for (int i = 2; i <= 2*n; i++) {
        int u = ans[i - 1];
        long long sum = (u == t);
        if(u == t && k == 1) break;

        for (int v: adj[u]) {
            int xx = x + d[u] - d[v] - c[u][v];
            if (sum + ff(v, xx) >= k) {
                ans[i] = v;
                k-=sum;
                x = xx;
                break;
            }
            sum += ff(v, xx);
        }
    }
    
    if (k != 1) {
        puts("-1");
        return 0;
    }
    int i = 1;
    for (i = 1; ans[i] != 0; i++);
    printf("%d\n", i - 1);
    for (int j = 1; j < i; j++) printf("%d ", ans[j]);
    puts("");
}
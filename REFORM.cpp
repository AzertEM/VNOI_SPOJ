#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 5;
long long n, m, cnt, bridge, c1, CC;
long long res;
long long low[N], num[N], parent[N], S[N];
vector <int> adj[N];
 
void DFS(int u) {
    if (CC == 0) c1++;
    low[u] = num[u] = ++cnt;
    S[u] = 1;
 
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (num[v] == 0) {
            parent[v] = u;
            DFS(v);
            S[u] += S[v];
            if (low[v] > num[u]) bridge++;
            low[u] = min(low[u], low[v]);
        }
        else if (v != parent[u])
            low[u] = min(low[u], num[v]);
    }
}
 
int main() {
    scanf("%lld%lld", &n, &m);
    int u, v;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for (int i = 1; i <= n; i++) {
        if (num[i] == 0) {
            DFS(i);
            CC++;
        }
    }
    if (CC >= 3) {
        printf("0");
        return 0;
    }
    
    if (CC == 2) res = 1LL * (m - bridge) * c1 * (n - c1);
    else {
        res = 1LL * (m - bridge) * (n * (n - 1)/2 - m);
        for (int i = 2; i <= n; i++) {
            if (num[i] == low[i]) res += 1LL * S[i] * (n - S[i]) - 1;
        }
    }
    printf("%lld", res);
}
#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 4;
int m, n, res, cnt;
int low[N], num[N];
bool in_stack[N];
stack <int> st;
vector <int> adj[N];

void DFS(int u) {
    low[u] = num[u] = ++cnt;
    st.push(u);
    in_stack[u] = true;

    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (num[v] == 0) DFS(v);
        if (in_stack[v] == true)
            low[u] = min(low[u], low[v]);
    }

    if (low[u] == num[u]) {
        res++;
        while (!st.empty() && st.top() != u) in_stack[st.top()] = false, st.pop();
        in_stack[st.top()] = false, st.pop();
    }
}

int main() {
    scanf("%d%d", &n, &m);
    int u, v;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) 
        if (num[i] == 0) DFS(i);

    printf("%d", res);
}
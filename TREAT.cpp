#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, next_i, cnt;
int num[N], low[N], f[N], SCC[N];
bool in_stack[N];
stack <int> st, SCC_st;
vector <int> adj[N];

void DFS_SCC(int u) {
    low[u] = num[u] = ++cnt;
    st.push(u), in_stack[u] = true;

    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (num[v] == 0) DFS_SCC(v);
        if (in_stack[v]) 
            low[u] = min(low[u], low[v]);
    }

    if (low[u] == num[u]) {

        int tmp = 0;
        while (st.top() != u && st.size()) {
            tmp++;
            SCC_st.push(st.top());
            in_stack[st.top()] = false, st.pop();
        }
        tmp++;
        SCC_st.push(st.top());
        in_stack[st.top()] = false, st.pop();
        while (!SCC_st.empty()) {
            SCC[SCC_st.top()] = tmp;
            SCC_st.pop();
        }
    }
}

int dp(int i) {
    if (SCC[i] != 1) return SCC[i];
    if (f[i] != -1) return f[i];
    if (adj[i][0] == i) return 1;
    
    f[i] = dp(adj[i][0]) + 1;
    return f[i];
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &next_i);
        adj[i].push_back(next_i);
    }

    memset(f, -1, sizeof(f));

    for (int i = 1; i <= n; i++)
        if (num[i] == 0) DFS_SCC(i);

    for (int i = 1; i <= n; i++) {
        printf("%d\n", dp(i));
    } 
}
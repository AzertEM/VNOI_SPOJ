#include <bits/stdc++.h>
using namespace std;

const int N = 2e4 + 4;
int n, m, cnt, res;
int low[N], num[N], color[N];
bool in_stack[N];
stack <int> st;
vector <int> adj[N];

int id(int a) {
    return a + 10000;
}

void eXit() {
    puts("NO");
    exit(0);
}

void setColor(int u, int x) {
    // cout << u << " " << x << "\n";
    if (color[id(u)] != 0 && color[id(u)] != x) {
        // cout << "HERE" << "\n";
        eXit();
    }

    if (color[id(-u)] != 0 && color[id(-u)] != 3 - x) {
        eXit();
    }

    // cout << -u << " " << 3 - x << "\n";
    color[id(u)] = x;
    color[id(-u)] = 3-x;
}

void DFS(int u) {
    low[u] = num[u] = ++cnt;
    st.push(u);
    in_stack[u] = true;

    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (num[v] == 0) DFS(v);
        if (in_stack[v] == true)
            low[u] = min(low[u], low[v]);
        if (color[v] == 1) setColor(u - 10000, 1);
    }

    if (low[u] == num[u]) {
        // set <int> s;
        res++;
        if (color[u] == 0) setColor(u - 10000, 2);
        while (!st.empty() && st.top() != u) in_stack[st.top()] = false, setColor(st.top() - 10000, color[u]), st.pop();
        in_stack[st.top()] = false, st.pop();
        // color[u] = u;
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        // cout << -u << " " << v << "\n";
        // cout << -v << " " << u << "\n";
        adj[id(-u)].push_back(id(v));
        adj[id(-v)].push_back(id(u));
    }

    for (int i = -m; i <= m; i++) {
        if (i == 0) continue; 
        if (num[id(i)] == 0) DFS(id(i));
    }
    
    bool valide = true;
    vector <int> ans;
    for (int i = 1; i <= m; i++) {
        // cout << color[id(i)] << " " << color[id(-i)] << "\n";
        // if (color[id(i)] == color[id(-i)]) valide = false;
        if (color[id(i)] == 2) ans.push_back(i);
    }

    // if (!valide) puts("NO");
    {
        puts("YES");
        printf("%d\n", (int)ans.size());
        for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
    } 
}
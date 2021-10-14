#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[] = {-1, 1, 0, 1, -1, 0, 1, -1};

const int N = 777;
int n, m;
int a[N][N];
bool visited[N][N];

bool dfs(int x, int y, int stt) {
    if (visited[x][y]) return stt;
    visited[x][y] = true;

    for (int i = 0; i < 8; i++) {
        int nextX = x + dx[i], nextY = y + dy[i];
        if (nextX == 0 || nextX > n || nextY == 0 || nextY > m) continue;
        if (a[nextX][nextY] != a[x][y]) {
            if (a[nextX][nextY] > a[x][y]) stt = false;
            continue;
        }
        stt = dfs(nextX, nextY, stt);
    }
    return stt;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        scanf("%d", &a[i][j]);
    // cout << dfs(4, 4, 1) << "\n";
    int res = 0;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        if (!visited[i][j]) res += dfs(i, j, 1);
    printf("%d\n", res);
}
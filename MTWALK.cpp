#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
const int N = 110;
int n;
int a[N][N];
bool visited[N][N];

bool BFS(int l, int r) {
    memset(visited, false, sizeof(visited));
    pair <int, int> u;
    queue <pair <int, int>> qList;
    
    if (a[1][1] >= l && a[1][1] <= r) qList.push(pair <int, int> (1, 1));

    while (!qList.empty()) {

        u = qList.front();
        qList.pop();

        for (int i = 0; i < 4; i++) {

            pair <int, int> v(u.X + dx[i], u.Y + dy[i]);

            if (v.X && v.X <= n && v.Y && v.Y <= n) {
                if (!visited[v.X][v.Y] && a[v.X][v.Y] >= l && a[v.X][v.Y] <= r) {
                    qList.push(v);
                    visited[v.X][v.Y] = true;
                    if (v.X == n && v.Y == n) return true;
                }
            }

        } 
    }

    return false;
}

bool check(int d) {
    for (int i = 0; i <= 110 - d; i++) {
        if (BFS(i, i + d)) return true;
    }
    return false;
}

void search(int l, int r) {
    if (r - l == 1) {
        if (check(l)) printf("%d", l);
        else printf("%d", r);
        exit(0);
    }

    int mid = (l + r)/2;
    if (check(mid)) search(l, mid);
    else search(mid, r);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
        scanf("%d", &a[i][j]);
    search(0, 110);
}
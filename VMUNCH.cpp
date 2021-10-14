#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
 
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
 
int r, c;
int a[101][101], f[101][101];
char s[101];
bool visited[101][101];
pair <int, int> start;
 
int value(char s) {
    if (s == 'B') return 2;
    if (s == '.') return 1;
    return 0;
}
 
void BFS(pair <int, int> t) {
    queue <pair <int, int> > q;
    q.push(t);
    visited[t.X][t.Y] = true;
 
    while (!q.empty()) {
        pair <int, int> u = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            pair <int, int> v = make_pair(u.X + dx[i], u.Y + dy[i]);
            if (!visited[v.X][v.Y] && a[v.X][v.Y] != 0) {
//                cout << u.X << " " <<u.Y << "\n";
                f[v.X][v.Y] = f[u.X][u.Y] + 1;
                q.push(v);
                visited[v.X][v.Y] = true;
            }
        }
    }
}
 
int main() {
//    freopen("VMUNCH.txt", "r", stdin);
    scanf("%d%d", &r, &c);
    for (int i = 1; i <= r; i++) {
        scanf("%s", s + 1);
        for (int j = 1; j <= c; j++) {
            if (s[j] != 'C') a[i][j] = value(s[j]);
            else start = make_pair(i, j), a[i][j] = 1;
        }
    }
 
    BFS(start);
 
    printf("%d", f[1][1]);
}
 
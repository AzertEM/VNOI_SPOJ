#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

const int N = 1e5 + 3;
int n;
int tail[N];
pair <int, int> a[N];

int BS(int tail[], int l, int r, int target) {
    if (r - l == 1) {
        return r;
    }

    int mid = (l + r) / 2;
    if (tail[mid] > target) return BS(tail, l, mid, target);
    return BS(tail, mid, r, target);
}

int main() {
    // freopen("PBCSEQ.inp", "r", stdin);
    // freopen("PBCSEQ.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &a[i].X, &a[i].Y); 
        a[i].X = -a[i].X;
    }

    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) a[i].X = -a[i].X;

    int res = 1;
    tail[1] = a[1].Y;
    for (int i = 2; i <= n; i++) {
        if (a[i].Y < tail[1])
            tail[1] = a[i].Y;
        
        else if (a[i].Y >= tail[res])
            tail[++res] = a[i].Y;

        else {
            int k = BS(tail, 0, res, a[i].Y);
            tail[k] = a[i].Y;
        }

    }
    printf("%d", res);
}
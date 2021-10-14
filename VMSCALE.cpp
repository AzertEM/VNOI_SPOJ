#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;
const int N = 1e4 + 5;
const int MAX_C = 70;
int a[N];
int L[N][MAX_C], R[N][MAX_C];

int cost(int m) {

    int idx = 0, a = 0, b = 0;
    bool nene = false;
    //a: have M
    //b: no M
    while (m > 0) {
        if (m % 3 == 2) {
            if (!nene) {
                a++;
                nene = true;
            }
        }
        if (m % 3 == 1) {
            if (nene) a++;
            else b++;
        }
        if (m % 3 == 0 && nene) {
            b++;
            nene = false;
        }
        m /= 3;
        idx++;
    }    
    if (nene) b++;
    return a + b;
}

void init() {
    for (int i = 0; i < N; i++) a[i] = cost(i);

    for (int i = 1; i < N; i++)
    for (int c = 0; c < MAX_C; c++)
        L[i][c] = R[i][c] = i;
    
    for (int i = 1; i < N; i++) {
        if (i > 1) L[i][min(a[i], a[i - 1])] = i - 1;
        if (i < N - 1) R[i][min(a[i], a[i + 1])] = i + 1;
    }
    for (int c = 0; c < MAX_C; c++) {
        for (int i = N - 1; i >= 1; i--) {
            if (i < N - 1) L[i][c] = min(L[i][c], L[i + 1][c]);
            if (c > 0) L[i][c] = min(L[i][c], L[i][c - 1]);
        }
        for (int i = 1; i < N; i++) {
            if (i > 0) R[i][c] = max(R[i][c], R[i - 1][c]);
            if (c > 0) R[i][c] = max(R[i][c], R[i][c - 1]);
        }

        for (int i = 1; i < N; i++) {
            if (c + a[i] >= MAX_C) continue; 
            if (i > 1) L[i][c + a[i]] = min(L[i - 1][c], L[i][c + a[i]]);
            if (i < N - 1) R[i][c + a[i]] = max(R[i + 1][c], R[i][c + a[i]]);
            if (i == 1 || i == N - 1) continue;

            for (int mc = 0; mc <= c; mc++) {
                L[R[i + 1][c]][c + a[i]] = min(L[i - 1][mc], L[R[i + 1][c]][c + a[i]]);
                L[R[i + 1][mc]][c + a[i]] = min(L[i - 1][c], L[R[i + 1][mc]][c + a[i]]);

                R[L[i - 1][c]][c + a[i]] = max(R[i + 1][mc], R[L[i - 1][c]][c + a[i]]);
                R[L[i - 1][mc]][c + a[i]] = max(R[i + 1][c], R[L[i - 1][mc]][c + a[i]]);
            }
        }
    }
}

int solve(int st, int ed) {
    int l = 0, r = MAX_C - 1;
    while (r - l > 1) {
        // cout << l << " " << 
        int mid = (l + r) / 2;
        if (L[ed][mid] <= st) r = mid;
        else l = mid;
    }
    if (L[ed][l] <= st) return l;
    return r;
}

int main() {
    // memset(f, -1, sizeof(f));
    init();
    int t;
    // cout << L[3][0] << "\n";
    scanf("%d", &t);
    while (t--) {
        int l, r;
        scanf("%d%d", &l, &r);
        cout << solve(l, r) << "\n";
        // cout << dp(l, r) << "\n";
    }
}
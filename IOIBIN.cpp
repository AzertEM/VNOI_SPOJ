#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 4;
int pset[N];

void initSet(int _size) {
    for (int i = 1; i <= _size; i++) pset[i] = i;
}

int findSet(int i) {
    return (pset[i] == i)? i : (pset[i] = findSet(pset[i]));
}

void unionSet(int i, int j) {
    pset[findSet(i)] = findSet(j);
}

bool isSameSet(int i, int j) {
    return findSet(i) == findSet(j);
}

int main() {
    // freopen("IOIBIN.inp", "r", stdin);
    // freopen("IOIBIN.out", "w", stdout);
    initSet(N - 1);
    int x, y, z, P;
    scanf("%d", &P);
    while (P--) {
        scanf("%d%d%d", &x, &y, &z);
        if (z == 1) unionSet(x, y);
        if (z == 2) cout << isSameSet(x, y) << "\n";
    }
}
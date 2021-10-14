#include <bits/stdc++.h>
using namespace std;

const int N = 17001;
int T, n, k;
int a[N];

void printRes(int a[], int n, int k) {
    deque <int> Q;
    Q.push_back(1);
    for (int i = 2; i <= n + 1; i++) {
        if (i > k) printf("%d ", a[Q.front()]);
        while (!Q.empty() && Q.front() <= i - k) Q.pop_front();

        while (!Q.empty() && a[i] <= a[Q.back()]) Q.pop_back();

        Q.push_back(i);
    }
}

int main() {
    scanf("%d", &T);
    while (T--) {
        memset(a, 0, sizeof(a));
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

        printRes(a, n, k);
        printf("\n");
    }
}
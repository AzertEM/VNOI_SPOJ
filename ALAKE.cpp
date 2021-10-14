#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int INF = 1e9 + 7;
const int N = 1e5 + 5;
int n;
int w[N], h[N];
int lulu[N], nunu[N];
long long res[N], sum[N];

long long wide(int i) {
    return sum[nunu[i] - 1] - sum[lulu[i]];
}

long long fill(int i) {
    return wide(i) * (min(h[nunu[i]], h[lulu[i]]) - h[i]);
}

int main() {
    int best = INF, start;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &w[i], &h[i]);
        if (h[i] < best) start = i, best = h[i];
        nunu[i] = i + 1, lulu[i] = i - 1;
        sum[i] = w[i] + sum[i - 1];
    }
    h[0] = h[n + 1] = INF;

    int williamp = start;
    long long time = 0;
    while (h[williamp] < INF) {
        // cout << nunu[williamp] << " " << lulu[williamp] << "\n";

        lulu[nunu[williamp]] = lulu[williamp];
        nunu[lulu[williamp]] = nunu[williamp];
        res[williamp] = time + wide(williamp);
        time += fill(williamp);

        if (h[nunu[williamp]] < h[lulu[williamp]]) {
            williamp = nunu[williamp];
            while (h[nunu[williamp]] < h[williamp]) williamp = nunu[williamp];
        }
        else {
            williamp = lulu[williamp];
            while (h[lulu[williamp]] < h[williamp]) williamp = lulu[williamp];
        }
    }

    for (int i = 1; i <= n; i++) cout << res[i] << "\n";
}
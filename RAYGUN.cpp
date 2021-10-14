#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 1e5;
int c[MAX], s[MAX];
bool isPrime[MAX];
long long m, n;
vector <int> ray;

void eratos() {
    // memset(isPrime, true, sizeof(isPrime));
    for (int i = 0; i < MAX; i++) c[i] = s[i] = isPrime[i] = 1;
    isPrime[1] = isPrime[0] = false;

    for (int i = 2; i < MAX; i++) {
        if (!isPrime[i]) continue;
        s[i] = i;
        c[i] *= -1;
        for (long j = i * 2; j < MAX; j += i) {
            s[j] *= i;
            c[j] *= -1;
            isPrime[j] = false;
        }
    }
}

int main() {
    eratos();
    for (int i = 2; i < MAX; i++) if (s[i] == i) ray.push_back(i);
    int t;
    scanf("%d", &t);
    for (int d = 1; d <= t; d++) {
        scanf("%lld%lld", &m, &n);

        if (m > n) swap(m, n);
        long long res = 0;
        for (int i = 0; i < ray.size(); i++) {
            int k = ray[i];
            if (k > m) break;
            res += -c[k] * (m / k) * (n / k);
        }

        printf("Case %d: %lld\n", d, (m) * (n) - res + (m != 0) + (n != 0));
    }
}
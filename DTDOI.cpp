#include <bits/stdc++.h>

using namespace std;
const int oo = 1 << 20;

int n, s, Max;
int a[101], f[100001];

int main() {
    scanf("%d%d", &n, &s);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        Max = max(Max, a[i]);
    }

    int m = 0;
    if (s > 10000) {
        m = (s - 10000) / Max + 1; 
        s -= m * Max;
    }
    
    for (int i = 1; i <= s; i++) f[i] = oo;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= s; j++) {
            if (f[j] != oo && j + a[i] <= s) f[j + a[i]] = min(f[j + a[i]], f[j] + 1);  
        }
    }
    printf("%d", f[s] + m);
}
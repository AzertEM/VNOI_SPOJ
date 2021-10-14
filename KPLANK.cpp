#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 6;
int n;
int a[N], r[N];
stack<int> lt, rt;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    
    int res = 0;
    lt.push(0);
    rt.push(n + 1);
    for (int i = n; i >= 1; i--) {
        while (a[i] <= a[rt.top()]) rt.pop();
        r[i] = rt.top();
        rt.push(i);
    }
    
    for (int i = 1; i <= n; i++) {
        while (a[i] <= a[lt.top()]) lt.pop();
        // cout << lt.top() << " " << r[i] << "\n";
        if (r[i] - lt.top() - 1 >= a[i]) res = max(res, a[i]);
        lt.push(i);
    }
    printf("%d\n", res);
}
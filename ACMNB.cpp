#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 6;
int n, res;
vector <int> job;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= 2 * n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        res += a;
        job.push_back(b - a);
    }
    sort(job.begin(), job.end());

    printf("%d", res + accumulate(job.begin(), job.begin() + n, 0));
}
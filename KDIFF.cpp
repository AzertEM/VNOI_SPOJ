#include <bits/stdc++.h>
using namespace std;

int const N = 3e5 + 1;
int n, k, maxPos, minPos, res;
int a[N], f[N];

deque <int> minQ, maxQ;

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    //F[i] là đoạn thỏa mãn đề dài nhất trong khoảng [1, i]
    //PosMax là số thỏa mãn max trong đoạn [Posmax..i] không lệch a[i] quá k
    //pos là số sao cho [pos..a[i]] thỏa mãn đề
    f[1] = 1;
    maxPos = minPos = 1;
    minQ.push_back(1); maxQ.push_back(1);

    for (int i = 2; i <= n; i++) {
        while (!maxQ.empty() && a[maxQ.back()] < a[i]) maxQ.pop_back();
        while (!maxQ.empty() && a[maxQ.front()] - a[i] > k) maxPos = maxQ.front() + 1, maxQ.pop_front();
        maxQ.push_back(i);

        while (!minQ.empty() && a[minQ.back()] > a[i]) minQ.pop_back();
        while (!minQ.empty() && a[i] - a[minQ.front()] > k) minPos = minQ.front() + 1, minQ.pop_front();
        minQ.push_back(i);

        int pos = max(maxPos, minPos);
        f[i] = max(i - pos + 1, f[i - 1]);
        res = max(res, i - pos + 1 + f[pos - 1]);
    }

    printf("%d", res);
}
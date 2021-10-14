#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;
const int N = 40;
const int MAX = 1e6 + 6;
int n, iDex, currentSum, maxS, maxT, zero;
int a[N], x[MAX], y[MAX], numS[MAX], numT[MAX];
int choice[2] = {1, -1};
vector <int> s, t;

//Choose i-th number from start to r?
void choose(int i, int end, int s[]) {
    if (i > end) {
        s[++iDex] = currentSum;
        return;
    }

    for (int k = 0; k < 2; k++) {
        currentSum += choice[k] * a[i];
        choose(i + 1, end, s);
        currentSum -= choice[k] * a[i];
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    choose(1, n / 2, x); maxS = iDex;
    iDex = currentSum = zero = 0;
    choose(n/2 + 1, n, y); maxT = iDex;

    //Find i and j so that |s[i] + t[j]| is min
    //Observe: |s[i] + t[j]| = |s[i] - (-t[j])| so we need to find min |s[i] - f[j]| with f[j] = -t[j]
    for (int i = 1; i <= maxT; i++) y[i] = -y[i];
    int l, r = 1, res = INF, cnt = 0;

    sort(x + 1, x + maxS + 1);
    sort(y + 1, y + maxT + 1);
    s.push_back(-INF);
    t.push_back(-INF);
    for (int i = 1; i <= maxS; i++) {
        if (x[i] == x[i - 1]) numS[s.size() - 1]++;
        else s.push_back(x[i]), numS[s.size() - 1] = 1;
    }
    for (int i = 1; i <= maxT; i++) {
        if (y[i] == y[i - 1]) numT[t.size() - 1]++;
        else t.push_back(y[i]), numT[t.size() - 1] = 1;
    }

    for (l = 1; l < s.size(); l++) {
        for (; r < t.size(); r++) if (t[r] > s[l]) break;
        int prevRes = res;
        if (r >= t.size()) {
            res = min(res, abs(s[l] - t[r - 1]));
            if (prevRes != res) cnt = numT[r - 1] * numS[l];
            else cnt += numT[r - 1] * numS[l] * (abs(s[l] - t[r - 1]) == res);
        }
        else
        if (r == 1) {
            res = min(res, abs(s[l] - t[r]));
            if (prevRes != res) cnt = numT[r] * numS[l];
            else cnt += numT[r] * numS[l] * (abs(s[l] - t[r]) == res);
        }
        else
        if (r > 1 && r < t.size()) {
            res = min(res, min(abs(s[l] - t[r - 1]), abs(s[l] - t[r])));
            if (prevRes != res) cnt = numS[l] * ((numT[r - 1] * (abs(s[l] - t[r - 1]) == res)) + (numT[r] * (abs(s[l] - t[r]) == res)));
            else cnt += numS[l] * ((numT[r - 1] * (abs(s[l] - t[r - 1]) == res)) + (numT[r] * (abs(s[l] - t[r]) == res)));
        }
    }

    cout << res << " " << cnt/2 << "\n";
}
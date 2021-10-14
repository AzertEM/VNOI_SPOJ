#include <bits/stdc++.h>
using namespace std;

const int N = 2200;
int n, res, choosed;
int a[N];
int f[N][1064];
map <int, int> chocho;
vector <int> b, val;

int dp(int id, int stt) {
    if (id > n) return 0;
    if (f[id][stt] != -1) return f[id][stt];

    int ret = 0;
    int nxt = b[id], can = true;
    for (int i = 1; i <= min(id - 1, 9); i++) {
        if (id == 1) break;
        if ((stt >> (i - 1)) & 1) {
            int prv = b[id - i];
            if (nxt - prv == 9 || nxt - prv == 8 || nxt - prv == 1) can = false;
        }
    }

    int newStt = (stt << 1) % (1 << 9);
    if (can) ret = max(ret, dp(id + 1, newStt + 1) + val[id]);
    ret = max(ret, dp(id + 1, newStt));

    return f[id][stt] = ret;
}

int main() {
    memset(f, -1, sizeof(f));
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        chocho[a[i]]++;
    }
    
    int m = n;
    b.push_back(0);
    val.push_back(0);

    for (map <int, int>::iterator it = chocho.begin(); it != chocho.end(); it++) {
        b.push_back(it->first);
        val.push_back(it->second);
    }
    n = val.size() - 1;
    printf("%d\n", m - dp(1, 0));
}
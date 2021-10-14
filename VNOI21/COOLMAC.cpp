#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int m, n, t = N;
pair <int, int> coat[N];

bool cmp(pair <int, int> a, pair <int, int> b) {
    if (a.second != b.second) return a.second > b.second;
    return a.first < b.first;
}

int main() {
	freopen("COOLMAC.inp", "r", stdin);
	freopen("COOLMAC.out", "w", stdout);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) scanf("%d%d", &coat[i].first, &coat[i].second);

    int tmp;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tmp);
        t = min(tmp, t);
    }
	sort(coat + 1, coat + m + 1, cmp);
	// for (int i = 1; i <= m; i++) cout << coat[i].first << " " << coat[i].second << "\n";
    // cout << endl;
    int idx = 1;
    if (coat[idx].second < 100000) {puts("-1"); return 0;}
    if (coat[idx].first == t) {puts("1"); return 0;}
    
    int minC = coat[idx].first, res = 1, cur = idx, can;
    // cout << coat[1].first << " " << coat[1].second << "\n";
    while (minC > t) {
		can = -1;
		while (coat[idx].second >= coat[cur].first && idx <= m) {
			if (coat[idx].first < minC) minC = coat[idx].first, can = idx;
			idx++;
		}
        // cout << coat[can].first << " " << coat[can].second << "\n";
        // cout << idx << " " << minC << "\n";
		if (can == -1) {puts("-1"); return 0;}
		cur = can;
		res++;
	}
	
    if (minC > t) puts("-1");
    else
	printf("%d\n", res);
}

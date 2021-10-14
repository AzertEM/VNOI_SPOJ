#include <bits/stdc++.h>
using namespace std;

int n;
vector <pair<int, int>> p;

int main() {
    scanf("%d", &n);
    int tmp;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tmp);
        p.push_back(make_pair(tmp, 0));
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tmp);
        p.push_back(make_pair(tmp, 1));
    }

    sort(p.begin(), p.end());
    int res = 0;
    for (int i = 1; i < p.size(); i++) {
        if (p[i].second != p[i - 1].second) res++, i++;
    }
    printf("%d\n", res);
}
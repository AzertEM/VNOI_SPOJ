#include <bits/stdc++.h>
using namespace std;

int m, k;
vector <pair <long long, int> > s;

long long S(vector <int> x, vector <int> y) {
    long long s = 0;
    int n = x.size();
    for (int i = 0; i < x.size(); i++) {
        s += (1LL * x[i] - x[(i + 1) % n]) * (1LL * y[i] + y[(i + 1) % n]); 
    }
    return (s < 0)? -s: s;
}

long long change(int c) {
    // cout << c << "\n";
    int l = 0, r = 0, cur = s[0].second != c;
    long long ret = 0, sum = s[0].first;

    while (r < s.size() && l < s.size()) {
        // cout << cur << " ";
        while (r < s.size() - 1 && cur < k) r++, cur += s[r].second != c, sum += s[r].first;
        while (r < s.size() - 1 && s[r + 1].second == c) r++, sum += s[r].first;
        ret = max(ret, sum);
        // cout << l << " " << r << "\n";
        l++;
        if (s[l - 1].second != c) cur--;
        sum -= s[l - 1].first;
    }

    return ret;
}

int main() {
    scanf("%d%d", &m, &k);
    for (int i = 1; i <= m; i++) {
        int n, c;
        vector <int> x, y;
        scanf("%d%d", &n, &c);
        for (int j = 1; j <= n; j++) {
            int a, b;
            scanf("%d%d", &a, &b);
            x.push_back(a);
            y.push_back(b);
        }
        s.push_back(make_pair(S(x, y), c));
    }

    sort(s.begin(), s.end());
    for (int i = s.size() - 1; i > 0; i--)
        s[i].first -= s[i - 1].first;
        // cout << s[i].first << " " << s[i].second << "\n";
    // cout << s[0].first << " " << s[0].second << "\n";
    long long res = 0;
    for (int i = 1; i <= m; i++)
        res = max(res, change(i));
    printf("%lld", res/2);

    if (res % 2) printf(".5\n");
    else printf(".0\n");
}
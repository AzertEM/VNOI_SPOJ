#include <bits/stdc++.h>
using namespace std;

long long l, r;
long long f[20][12][2];

void getDigit(long long a, vector <int> &digit) {
    while (a != 0) {
        digit.push_back(a % 10);
        a /= 10;
    }
}

long long lucky(int idx, int lastDig, int tight, vector <int> &digit) {
    if (idx == -1) return 1;

    if (f[idx][lastDig][tight] != -1 && tight != 1) return f[idx][lastDig][tight];

    long long ans = 0;
    int k = (tight)? digit[idx] : 9;

    for (int i = 0; i <= k; i++) {
        if (lastDig != 1 || i != 3) {
            int newTight = (digit[idx] == i)? tight : 0;
            ans += lucky(idx - 1, i, newTight, digit);
        }
    }

    if (!tight) f[idx][lastDig][tight] = ans;

    return ans;
}

long long res(long long a) {
    vector <int> digit;
    getDigit(a, digit);
    return lucky(digit.size() - 1, 0, 1, digit);
}

int main() {
    while(scanf("%lld%lld", &l, &r) != EOF){
        memset(f, -1, sizeof(f));
        cout << res(r) - res(l - 1) << "\n";
    }
}
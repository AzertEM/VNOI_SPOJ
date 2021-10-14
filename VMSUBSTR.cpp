#include <bits/stdc++.h>
using namespace std;

int L;
string s;
int cnt[53][53], in[53];
int id[300];

int main() {
    int cur = 0;
    for (int i = 'A'; i <= 'Z'; i++) id[i] = cur++;
    for (int i = 'a'; i <= 'z'; i++) id[i] = cur++;
    // cout << cur << "\n";
    scanf("%d", &L);
    cin >> s;
    
    for (int i = 0; i < s.size() - 1; i++)
        cnt[id[s[i]]][id[s[i + 1]]]++;
    
    int q;
    scanf("%d", &q);
    string inp;
    // memset(in, 0, sizeof(in));
    while (q--) {
        cin >> inp;
        for (int i = 0; i < inp.size(); i++) in[id[inp[i]]] = 1;

        int res = 0;
        for (int i = 0; i < 52; i++)
        for (int j: inp) {
            // cout << id[j] << " ";
             if (!in[i]) res += cnt[i][id[j]];
        }
        res += in[id[s[0]]];
        printf("%d\n", res);
        for (int i = 0; i < inp.size(); i++) in[id[inp[i]]] = 0;
    }
}
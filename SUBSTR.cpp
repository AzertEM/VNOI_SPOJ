#include <bits/stdc++.h>
#define long long long
using namespace std;

const long base = 31;
const long MOD = 1e9 + 7;
const long N = 1e6 + 5;

char a[N], b[N];
long POW[N], hashA[N];

//Return the hash value of a[i .. j]
long getHash(int i, int j) {
    return (hashA[j] - hashA[i - 1] * POW[j - i + 1] + MOD * MOD) % MOD;
}

int main() {
    scanf("%s", a + 1);
    scanf("%s", b + 1);
    int lenA = strlen(a + 1);
    int lenB = strlen(b + 1);

    int hashB = 0;
    for (int i = 1; i <= lenB; i++) 
        hashB = (hashB * base + b[i] - 'a' + 1) % MOD;

    //POW[i] is base ^ i
    POW[0] = 1;
    for (int i = 1; i < N; i++) 
        POW[i] = (POW[i - 1] * base) % MOD;
    
    //Hash[i] is the hash value of a[1 .. i]
    hashA[0] = 0;
    for (int i = 1; i <= lenA; i++)
        hashA[i] = (hashA[i - 1] * base + a[i] - 'a' + 1) % MOD;
    
    for (int i = 1; i <= lenA - lenB + 1; i++) {
        if (hashB == getHash(i, i + lenB - 1)) printf("%d ", i);
    }
}
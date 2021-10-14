#include <bits/stdc++.h>
#define long long long
using namespace std;

const int N = 3e5 + 3;
int n;
long arr[N], tail[N];

//Return the indicate of largest element smaller than x in array a[]
int BinarySearch(long a[], int l, int r, long x) {
    if (r - l == 1 || l == r) {
        return r;
    }

    int mid = (l + r) / 2;
    if (a[mid] >= x) return BinarySearch(a, l, mid, x);
    return BinarySearch(a, mid, r, x);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &arr[i]);

    int res = 1;
    //Tail[i] is the last element of subsequence whose length is i
    tail[1] = arr[1];

    for (int i = 2; i <= n; i++) {

        //Case 1
        if (arr[i] < tail[1]) 
            tail[1] = arr[i];

        //Case 2
        else if (arr[i] > tail[res])
            tail[++res] = arr[i];

        //Case 3
        else {
            int k = BinarySearch(tail, 0, res, arr[i]);
            tail[k] = arr[i];
        }
    }

    printf("%d", res);
}
#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int N = 2e4 + 5;
int n, k;
iii worker[N];

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", &worker[i].se.fi, &worker[i].se.fi, &worker[i].fi);
    }
    sort(worker + 1, worker + n + 1);

    //fi: position
    //se.fi: length
    //se.se: price
    int idx = 1;
    for (int i = worker[1].fi; i <= n; i++) {

    }
}

// /*
//     Bài này dp thì rất cơ bản, song để AC thì cần thay đổi tư duy
//     Bình thường các bạn sẽ toàn làm 3 lặp:
//       for(n):
//          for(k):
//             for(n):
//     Tuy nhiên bài này ta sẽ đảo 2 vòng lặp đầu để nhận ra cách tối ưu thuật toán bằng cây IT, chi tiết xem code
// */
// #define NguyenDangQuan the_author
// #define my_heart love_you_to_the_moon_and_back
 
// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// using ld = long double;
// using ull = unsigned long long;
 
// bool typetest;
// inline void fastIOfileinput()
// {
// 	ios::sync_with_stdio(0);
// 	cin.tie(0);
// 	cout.tie(0);
// 	typetest = 0;
// }
 
// const int N = 1e5 + 2;
// struct Tho
// {
// 	int l, s, p;
// 	bool operator<(const Tho &a) const
// 	{
// 		return s < a.s;
// 	}
// } a[N];
// int n, k;
// const ll Inf = 1e14;
// ll dp[N][105];
// ll st[N * 4];
 
// void Read()
// {
// 	cin >> n >> k;
// 	++n;
// 	for (int i = 1; i <= k; ++i)
// 		cin >> a[i].l >> a[i].p >> a[i].s,
// 			++a[i].s;
// 	sort(a + 1, a + k + 1);
// }

//  //// f(i, j) là số tiền nhiều nhất thu được nếu ở vị trí thứ i chọn j làm thằng sơn
// //// dp(i, j) : là max tất cả các f(i, t) mà t <= j
// //// => dp(i, j) = max(dp(t, j - 1) + (i - t) * a[j].p) với mọi t : 0 -> i
 
// void Upd(int id, int l, int r, int &pos, ll v)
// {
// 	if (l > pos || r < pos)
// 		return;
// 	if (l == r && r == pos)
// 	{
// 		st[id] = max(st[id], v);
// 		return;
// 	}
// 	Upd(id << 1, l, (l + r) / 2, pos, v);
// 	Upd(id << 1 | 1, (l + r) / 2 + 1, r, pos, v);
// 	st[id] = max(st[id << 1], st[id << 1 | 1]);
// }
 
// ll Get(int id, int l, int r, int a, int b)
// {
// 	if (l > b || r < a)
// 		return -Inf;
// 	if (l >= a && r <= b)
// 		return st[id];
// 	return max(Get(id << 1, l, (l + r) / 2, a, b), Get(id << 1 | 1, (l + r) / 2 + 1, r, a, b));
// }
 
// void Solve()
// {
// 	fill_n(&dp[0][0], N * 105, -Inf);
// 	dp[1][0] = 0;
// 	for (int j = 1; j <= k; ++j)
// 	{
// 		fill_n(st, N * 4, -Inf);
// /// Đây là vòng lặp đầu bị đảo vào trong
// 		for (int i = 1; i <= n; ++i)
// 			dp[i][j] = dp[i][j - 1],
// 			Upd(1, 1, n, i, dp[i][j - 1] - (ll)i * a[j].p);
// /// Lúc này vòng lặp thứ 3 không còn bị lồng vào trong vòng lặp đầu nữa 
// 		for (int i = a[j].s; i < a[j].s + a[j].l; ++i)
// 		{
// 			dp[i][j] = max(dp[i][j], Get(1, 1, n, max(i - a[j].l, 1), a[j].s - 1) + (ll)i * a[j].p);
// 		}
// 	}
// 	/*for (int i = 2; i <= n; ++i)
// 		for (int j = 1; j <= k; ++j)
// 			cout << dp[i][j] << (j == k ? "\n" : " ");*/
// 	ll ans = -Inf;
// 	for (int i = n; i > 1; --i)
// 		ans = max(ans, dp[i][k]);
// 	cout << ans;
// }
 
// int32_t main()
// {
// 	fastIOfileinput();
// 	if (typetest)
// 	{
// 		int t;
// 		cin >> t;
// 		while (t--)
// 		{
// 			Read();
// 			Solve();
// 		}
// 	}
// 	else
// 	{
// 		Read();
// 		Solve();
// 	}
// }
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;
typedef pair <ii, ii> iiii;

const int INF = 1e9 + 5;
const int N = 1e5 + 5;
int n, q, sz;
int dsu[N];
bool is_backup;
vector <ii> backup;
vector <iii> query;
vector <iiii> e, overwatch;
map <ii, int> done;
map <ii, vector <ii> > mp;

void setpar(int u, int x){
    if(is_backup) backup.push_back(ii(u, dsu[u]));
    dsu[u] = x;
}

int find(int i) {
    if(dsu[i] == i) return i;
    setpar(i, find(dsu[i]));
    return dsu[i];
}

void join(int i, int j) {
    setpar(find(i), find(j));   
}

void rollback(){
    while(backup.size()){
        ii top = backup[backup.size()-1];
        backup.pop_back();
        dsu[top.first] = top.second;
    }
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= q; i++) {
        int t, x, y;
        scanf("%d%d%d", &t, &x, &y);
        if (x > y) swap(x, y);
        if (t == 1) {
            mp[ii(x, y)].push_back(ii(i, INF));
        }
        if (t == 2) {
            if (done[ii(x, y)] == mp[ii(x, y)].size()) continue;
            mp[ii(x, y)][done[ii(x, y)]].se = i;
            done[ii(x, y)]++;
        }
        if (t == 3) {
            query.push_back(iii(i, ii(x, y)));
        }
    }

    for (map <ii, vector <ii>>::iterator it = mp.begin(); it != mp.end(); it++) {
        for (ii t: it->second) {
            e.push_back(iiii(ii(it->first.fi, it->first.se), t));
        }
    }

    sort(query.begin(), query.end());
    int i = 0;

    sz = sqrt(q);
    int l = 1, r;
    while (l <= q) {
        overwatch.clear();
        r = min(q, l + sz - 1);

        is_backup = false;
        for (int i = 1; i <= n; i++) dsu[i] = i;
        for (int i = 0; i < e.size(); i++) {
            int u = e[i].fi.fi, v = e[i].fi.se;
            int tin = e[i].se.fi;
            int tout = e[i].se.se;
            if (tin <= l && r <= tout)
                join(u, v);
            else if (l <= tout && tin <= r) overwatch.push_back(e[i]);
        }
        is_backup = true;

        for (; i < query.size() && query[i].fi <= r; i++) {
            for (int j = 0; j < overwatch.size(); j++) {
                int u = overwatch[j].fi.fi, v = overwatch[j].fi.se;
                int tin = overwatch[j].se.fi;
                int tout = overwatch[j].se.se;
                if (tin <= query[i].fi && query[i].fi <= tout) {
                    join(u, v);
                }
            }
            if (find(query[i].se.fi) == find(query[i].se.se)) printf("1");
            else printf("0");
            rollback();
        }
        l = r + 1;
    }
    printf("\n");
}
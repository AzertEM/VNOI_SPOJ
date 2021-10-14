#include <bits/stdc++.h>

using namespace std;

#define fst first
#define snd second

typedef long long int64;
typedef pair<int, int> ii;

const int MAXN = 1e3 + 9;

struct edg{ int pos, cap, rev; };

vector<edg> gph[MAXN];

void clear(){ for(int i=0; i<MAXN; i++) gph[i].clear(); }

void add_edge(int s, int e, int x){
    gph[s].push_back({e, x, (int)gph[e].size()});
    gph[e].push_back({s, 0, (int)gph[s].size()-1});
}

int dis[MAXN], pnt[MAXN];

bool bfs(int src, int sink){
    memset(dis, 0, sizeof(dis));
    memset(pnt, 0, sizeof(pnt));
    queue<int> que;
    que.push(src);
    dis[src] = 1;
    while(!que.empty()){
        int x = que.front();
        que.pop();
        for(auto &e : gph[x]){
            if(e.cap > 0 && !dis[e.pos]){
                dis[e.pos] = dis[x] + 1;
                que.push(e.pos);
            }
        }
    }
    return dis[sink] > 0;
}

int dfs(int x, int sink, int f){
    if(x == sink) return f;
    for(; pnt[x] < gph[x].size(); pnt[x]++){
        edg e = gph[x][pnt[x]];
        if(e.cap > 0 && dis[e.pos] == dis[x] + 1){
            int w = dfs(e.pos, sink, min(f, e.cap));
            if(w) {
                gph[x][pnt[x]].cap -= w;
                gph[e.pos][e.rev].cap += w;
                return w;
            }
        }
    }
    return 0;
}

int64 match(int src, int sink){
    int64 ret = 0;
    while(bfs(src, sink)){
        int r;
        while((r = dfs(src, sink, 2e9))) ret += r;
    }
    return ret;
}

int main(){
    int n, m, s, t;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    while(m--){
        int u, v , c;
        scanf("%d%d%d", &u, &v, &c);
        add_edge(u, v, c);
    }
    cout << match(s, t) << "\n";
}
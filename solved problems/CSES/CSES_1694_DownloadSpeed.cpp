/*
Reference: https://cp-algorithms.com/graph/edmonds_karp.html
Tested at: https://cses.fi/problemset/task/1694/
*/
#include <bits/stdc++.h>
using namespace std;

#define int     long long
#define sz(x)   (int)size(x)
#define all(x)  begin(x), end(x)

const int MAXN = 512;
const int INF  = 0x3f3f3f3f3f3f3f3fLL;

int n, m, s, t;
int c[MAXN][MAXN]{};
vector<int> adj[MAXN], pred;
//int cont;

int bfs() {
    fill(all(pred), -1);
    pred[s] = s;
    queue<pair<int,int>> q; // {vertex, capacity}
    q.push({s, INF});
    while (!q.empty()) {
        int at   = q.front().first;
        int flow = q.front().second;
        q.pop();
        for (auto to : adj[at]) {
            if (pred[to] == -1 && c[at][to]) {
                pred[to] = at;
                int new_flow = min(flow, c[at][to]);
                if (to == t) return new_flow;
                q.push({to, new_flow});
            }
        }
    }
    return 0;
}

int maxflow() {
    int flow = 0, new_flow;
    pred.resize(MAXN);
    while ((new_flow = bfs())) {
        flow += new_flow;
        int at = t;
        //vector<int> path;
        while(at != s){
            //path.push_back(at);
            int to = pred[at];
            c[to][at] -= new_flow;
            c[at][to] += new_flow;
            at = to;
        }
        //path.push_back(s); reverse(all(path)); for(auto v : path) cout << v << ' '; cout << "+" << new_flow << '\n';
        //++cont;
    }
    //cout << "halt after " << cont << " iteration(s)\n";
    return flow;
}

signed main() {
    cin >> n >> m;
    s = 1; t = n;
    for (int i = 0; i < m; ++i) {
        int x, y, cap; cin >> x >> y >> cap;
        adj[x].push_back(y);
        adj[y].push_back(x);
        c[x][y] += cap;
        //c[y][x] += cap; // if G is undirected
    }
    cout << maxflow() << '\n';
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct edge{
    int v, w;
    edge(int vi, int wi) : v(vi), w(wi) {}
};

void dijkstra(int s, vector<vector<edge>> &adjacency, vector<int> &dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> active;
    dist[s]=0;
    active.push({0, s});
    while(!active.empty()) {
        auto [curr, u] = active.top();
        active.pop();
        if(dist[u]<curr) {
            continue;
        }
        for(auto [v, w] : adjacency[u]) {
            if(dist[v]>curr+w) {
                dist[v]=curr+w;
                active.push({dist[v], v});
            }       
        }
    }
    return;
}

void solve() {
    return;
}

int main() {
#ifdef bipinpathak
    (void)!freopen("input.txt", "r", stdin);
    (void)!freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n=500, m=1000;
map<pair<int, int>, ll> capacity;
vector<vector<int>> adjacency(n+1);
vector<int> parent(n+1);

ll go() {
	fill(parent.begin(), parent.end(), 0);
	parent[1]=-1;
	queue<pair<int, ll>> active;
	active.push({1, 1e9});
	while(!active.empty()) {
		int u=active.front().first;
		ll flow=active.front().second;
		active.pop();
		for(auto v : adjacency[u]) {
			if(parent[v] || !capacity[make_pair(u, v)]) {
				continue;
			}
			parent[v]=u;
			if(v==n) {
				return min(flow, capacity[make_pair(u, v)]);
			}
			active.push({v, min(flow, capacity[make_pair(u, v)])});
		}
	}
	return 0;
}

void solve() {
	cin>>n>>m;
	while(m--) {
		int u, v, c;
		cin>>u>>v>>c;
		capacity[make_pair(u, v)]+=c;
		adjacency[u].push_back(v);
		adjacency[v].push_back(u);
	}
	ll ans=0;
	while(1) {
		ll add=go();
		if(!add) {
			break;
		}
		ans+=add;
		int curr=n;
		while(curr!=1) {
			capacity[make_pair(parent[curr], curr)]-=add;
			capacity[make_pair(curr, parent[curr])]+=add;
			curr=parent[curr];
		}
	}
	cout<<ans<<endl;
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
    while(t--) {
        solve();
    }
    return 0;
}


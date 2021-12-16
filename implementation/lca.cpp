#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void update(int l, int r, int index, vector<int> &seg, int start, int end, int val) {
    if(!(end<l || start>r)) {
        if(start<=l && r<=end) {
            seg[index]=val;
        } else {
            int mid=l+(r-l)/2;
            update(l, mid, index+1, seg, start, end, val);
            update(mid+1, r, index+2*(mid-l+1), seg, start, end, val);
            seg[index]=min(seg[index+1], seg[index+2*(mid-l+1)]);
        }
    }
    return;
}
 
int query(int l, int r, int index, vector<int> &seg, int start, int end) {
    int ans=1e9;
    if(!(end<l || start>r)) {
        if(start<=l && end>=r) {
            ans=seg[index];
        } else {
            int mid=l+(r-l)/2;
            ans=min(query(l, mid, index+1, seg, start, end), query(mid+1, r, index+2*(mid-l+1), seg, start, end));
        }
    }
    return ans;
}


void go(int p, int u, vector<vector<int>> &adjacency, vector<int> &order, vector<int> &height, int h, vector<int> &index) {
    height[u]=h;
    index[u]=(int)order.size();
    order.push_back(u);
    h++;
    for(auto v : adjacency[u]) {
        if(v==p) {
            continue;
        }
        go(u, v, adjacency, order, height, h, index);
        order.push_back(u);
    }
    return;
}

void build(vector<vector<int>> &adjacency, vector<int> &height, vector<int> &index, vector<int> &order) {
    go(0, 1, adjacency, order, height, 0, index); 
    int m=(int)order.size()-1;
    vector<int> seg(2*m+1, 1e9);
    for(int i=1; i<=m; i++) {
        update(1, m, 1, seg, i, i, height[order[i]]);
    }
    return;
}

int dist(int a, int b, vector<int> &index, vector<int> &seg, int m, vector<int> &height) {
    int l, r;
    l=index[a], r=index[b];
    if(l>r) {
        swap(l, r);
    }
    int lca=query(1, m, 1, seg, l, r);
    int ans=height[a]+height[b]-2*lca;
    return ans;
}

void solve() {
    //1 based indexing
    int n;
    cin>>n;
    vector<vector<int>> adjacency(n+1);
    vector<int> height(n+1), index(n+1), order={0};
    for(int i=0; i<n-1; i++) {
        int a, b;
        cin>>a>>b;
        adjacency[a].push_back(b);
        adjacency[b].push_back(a);
    }
    return;
}

int main() {
#ifdef bipinpathak
    (void)!freopen("input.txt", "r", stdin);
    (void)!freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    auto start=clock();
    int t = 1;
    //cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}


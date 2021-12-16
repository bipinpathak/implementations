#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void push(int l, int r, int index, vector<ll> &seg, vector<ll> &lazy) {
    int mid=l+(r-l)/2;
    lazy[index+1]+=lazy[index];
    seg[index+1]+=lazy[index];
    lazy[index+2*(mid-l+1)]+=lazy[index];
    seg[index+2*(mid-l+1)]+=lazy[index];
    lazy[index]=0;
    return;
}

void update(int l, int r, int index, vector<ll> &seg, int start, int end, ll val, vector<ll> &lazy) {
    if(!(end<l || start>r)) {
        if(start<=l && r<=end) {
            seg[index]+=val;
            lazy[index]+=val;
        } else {
            push(l, r, index, seg, lazy);
            int mid=l+(r-l)/2;
            update(l, mid, index+1, seg, start, end, val, lazy);
            update(mid+1, r, index+2*(mid-l+1), seg, start, end, val, lazy);
            seg[index]=min(seg[index+1], seg[index+2*(mid-l+1)]);
        }
    }
    return;
}
 
ll query(int l, int r, int index, vector<ll> &seg, int start, int end, vector<ll> &lazy) {
    ll ans=1e18;
    if(!(end<l || start>r)) {
        if(start<=l && end>=r) {
            ans=seg[index];
        } else {
            push(l, r, index, seg, lazy); 
            int mid=l+(r-l)/2;
            ans=min(query(l, mid, index+1, seg, start, end, lazy), query(mid+1, r, index+2*(mid-l+1), seg, start, end, lazy));
        }
    }
    return ans;
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
    int t = 1;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

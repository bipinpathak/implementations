#include "bits/stdc++.h"
using namespace std;
using ll = long long;

struct node{
    int low=0, high=0;
};

void push(int l, int r, int index, vector<node> &seg, vector<int> &lazy) {
    int mid=l+(r-l)/2;
    lazy[index+1]+=lazy[index];
    seg[index+1].high+=lazy[index];
    seg[index+1].low+=lazy[index];
    lazy[index+2*(mid-l+1)]+=lazy[index];
    seg[index+2*(mid-l+1)].high+=lazy[index];
    seg[index+2*(mid-l+1)].low+=lazy[index];
    lazy[index]=0;
    return;
}

void update(int l, int r, int index, vector<node> &seg, int start, int end, int val, vector<int> &lazy) {
    if(!(end<l || start>r)) {
        if(start<=l && r<=end) {
            seg[index].high+=val;
            seg[index].low+=val;
            lazy[index]+=val;
        } else {
            push(l, r, index, seg, lazy);
            int mid=l+(r-l)/2;
            update(l, mid, index+1, seg, start, end, val, lazy);
            update(mid+1, r, index+2*(mid-l+1), seg, start, end, val, lazy);
            seg[index].low=min(seg[index+1].low, seg[index+2*(mid-l+1)].low);
            seg[index].high=max(seg[index+1].high, seg[index+2*(mid-l+1)].high);
        }
    }
    return;
}
 
node query(int l, int r, int index, vector<node> &seg, int start, int end, vector<int> &lazy) {
    node ans;
    ans.high=INT_MIN;
    ans.low=INT_MAX;
    if(!(end<l || start>r)) {
        if(start<=l && end>=r) {
            ans=seg[index];
        } else {
            push(l, r, index, seg, lazy); 
            int mid=l+(r-l)/2;
            auto left=query(l, mid, index+1, seg, start, end, lazy), right=query(mid+1, r, index+2*(mid-l+1), seg, start, end, lazy);
            ans.high=max(left.high, right.high);
            ans.low=min(left.low, right.low);
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
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}


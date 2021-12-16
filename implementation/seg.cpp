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
            seg[index]=seg[index+1]+seg[index+2*(mid-l+1)];
        }
    }
    return;
}
 
int query(int l, int r, int index, vector<int> &seg, int start, int end) {
    int ans=0;
    if(!(end<l || start>r)) {
        if(start<=l && end>=r) {
            ans=seg[index];
        } else {
            int mid=l+(r-l)/2;
            ans=query(l, mid, index+1, seg, start, end)+query(mid+1, r, index+2*(mid-l+1), seg, start, end);
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
    auto start=clock();
    int t = 1;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}


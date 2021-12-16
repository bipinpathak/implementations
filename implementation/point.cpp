#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void update(int l, int r, int index, vector<ll> &seg, int target, ll val) {
    if(target>=l && target<=r) {
        if(l==r && target==l) {
            seg[index]=val;
        } else {
            int mid=l+(r-l)/2;
            update(l, mid, index+1, seg, target, val);
            update(mid+1, r, index+2*(mid-l+1), seg, target, val);
            seg[index]=__gcd(seg[index+1], seg[index+2*(mid-l+1)]);
        }
    }
    return;
}
 
ll query(int l, int r, int index, vector<ll> &seg, int start, int end) {
    ll ans=0;
    if(!(end<l || start>r)) {
        if(start<=l && end>=r) {
            ans=seg[index];
        } else {
            int mid=l+(r-l)/2;
            ans=__gcd(query(l, mid, index+1, seg, start, end), query(mid+1, r, index+2*(mid-l+1), seg, start, end));
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
    cin >> t;
    for(int i=0; i<t; i++) {
        cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}


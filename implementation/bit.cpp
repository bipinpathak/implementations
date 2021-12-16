#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void add(int index, int val, vector<int> &a) {
    int n=(int)a.size();
    while(index<n) {
        a[index]+=val;
        index+=index&-index;
    }
    return;
}

int get(int index, vector<int> &a) {
    int ans=0;
    while(index) {
        ans+=a[index];
        index-=index&-index;
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
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}


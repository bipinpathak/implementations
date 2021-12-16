#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> lp, primes;

void build(int high) {
    lp.resize(high+1);
    lp[1]=1;
    for(int i=2; i<=high; i++) {
        if(lp[i]==0) {
            lp[i]=i;
            primes.push_back(i);
        }
        for(auto p : primes) {
            if(p>high/i || p>lp[i]) {
                break;
            }
            lp[p*i]=p;
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
    auto start=clock();
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}


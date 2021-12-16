#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> primes;

void pre() {
    int n=1e9+9, div, low=2, high=0;
    div=sqrt(n);
    while(low<=n) {
        high=min(low+div, n);    
        vector<int> lp(high-low+1, 0);
        for(auto p : primes) {
            if((ll)p*p>high) {
                break;
            }
            int curr=max(p*p, ((low+p-1)/p)*p);
            while(curr<=high) {
                if(lp[curr-low]==0) {
                    lp[curr-low]=p;
                }
                curr+=p;
            }
        }
        for(int curr=low; curr<=high; curr++) {
            if(lp[curr-low]==0) {
                primes.push_back(curr);
                lp[curr-low]=curr;
            }
            for(auto p : primes) {
                if(p>lp[curr-low] || (ll)p*curr>high) {
                    break;
                }
                lp[curr*p-low]=p;
            }
        }
        low=high+1;
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
    pre();
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

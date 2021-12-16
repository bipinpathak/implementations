#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll mod=1e9+7;

vector<vector<ll>> multiply(vector<vector<ll>> &a, vector<vector<ll>> &b) {
    int r1=(int)a.size(), c1=(int)a.front().size(), c2=(int)b.front().size();
    vector<vector<ll>> ans(r1, vector<ll> (c2));
    for(int i=0; i<r1; i++) {
        for(int j=0; j<c2; j++) {
            for(int k=0; k<c1; k++) {
                ans[i][j]=(ans[i][j]+(a[i][k]*b[k][j])%mod)%mod;
            }
        }
    }
    return ans;
}

vector<vector<ll>> power(vector<vector<ll>> a, ll x) {
    int n=(int)a.size();
    vector<vector<ll>> ans(n, vector<ll> (n));
    for(int i=0; i<n; i++) {
        ans[i][i]=1;
    }
    while(x) {
        if(x&1) {
            ans=multiply(ans, a);
        }
        a=multiply(a, a);
        x=x>>1;
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


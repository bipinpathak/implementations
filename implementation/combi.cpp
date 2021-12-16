#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

int rand(int l, int r) {
    uniform_int_distribution<int> uni(l, r);
    return uni(mt);
}

ll mod=1e9+7;

ll power(ll a, ll x) {
    a%=mod;
    if(a==0) {
        return a;
    }
	ll ans=1;
	while(x) {
		if(x&1) {
			ans=(ans*a)%mod;
		}
		x=x>>1;
		a=(a*a)%mod;
	}
	return ans;
}

ll modInv(ll a) {
	return power(a, mod-2);
}

vector<ll> fac, invFac;

ll ncr(ll n, ll r) {
	ll ans=1;	
	if(r!=0 && r!=n) {
		ans=fac[n];
        ans=(ans*invFac[r])%mod;
        ans=(ans*invFac[n-r])%mod;
	}
	return ans;
}

void pre(int n) {
	ll x=1;
	fac.push_back(x);
	for(ll i=1; i<=n; i++) {
		x=(x*i)%mod;
		fac.push_back(x);
	}
    invFac.resize(n+1);
    invFac[n]=modInv(fac[n]);
    for(int i=n-1; i>=0; i--) {
        invFac[i]=((i+1)*invFac[i+1])%mod;
    }
	return;
}

ll gcd(ll a, ll b) {
    if(b==0) {
        return a;
    }
    return gcd(b, a%b);
}

void solve() {
    return;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

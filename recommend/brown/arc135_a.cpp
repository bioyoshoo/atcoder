#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;

map<ll, ll> memo;
ll rec(ll x) {
    if (memo.count(x)) return memo[x];
    if (x <= 3) return x;
    ll v = rec(x / 2) * rec((x + 1) / 2) % mod;
    memo[x] = v;
    return memo[x];
}

int main() {
    ll X; cin >> X;
    
    cout << rec(X) << endl;
}
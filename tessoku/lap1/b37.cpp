#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

map<ll, int> memo;

ll rec(ll N) {
    if (N < 10) return N;
    if (memo[N] != 0) return memo[N];
    
    return memo[N] = rec(N / 10) + rec(N % 10);
}

int main() {
    ll N; cin >> N;

    cout << rec(N) << endl;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

ll dp[50];

ll fibo(ll n) {
    if (n == 0) return 1;
    else if (n == 1) return 1;
    else if (dp[n] != -1) return dp[n];
    return dp[n] = fibo(n - 1) + fibo(n - 2);
}

int main() {
    ll n; cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << fibo(n) << endl;
}

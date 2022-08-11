#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

ll memo[50];
ll fibo(int n) {
    if (n == 0) return 1;
    if (n == 1) return 1;
    if (memo[n] != -1) return memo[n];
    return memo[n] = fibo(n - 1) + fibo(n - 2);
}

int main() {
    int n; cin >> n;
    memset(memo, -1, sizeof(memo));
    cout << fibo(n) << endl;
}
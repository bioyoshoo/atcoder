#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll A, B, K; cin >> A >> B >> K;

    cout << max(0LL, A - K) << " " << max(0LL, B - max(0LL, K - A)) << endl;
}
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int L1, R1, L2, R2; cin >> L1 >> R1 >> L2 >> R2;

    int L = max(L1, L2), R = min(R1, R2);
    int ans = max(0, R - L);
    cout << ans << endl;
}
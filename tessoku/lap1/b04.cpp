#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    
    int ans = 0, a = 1;
    while (N > 0) {
        if (N % 10 == 1) ans += a;
        a *= 2;
        N /= 10;
    }

    cout << ans << endl;
}

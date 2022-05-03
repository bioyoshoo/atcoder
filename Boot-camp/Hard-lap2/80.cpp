#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int64_t ans = 0;
    if (K != 0) {
        for (int b = 1; b <= N; b++) {
            if (K >= b) continue;
            int64_t m = (N + 1) / b;
            ans += m * (b - K);
            int64_t L = m * b + K;
            int64_t R = N;
            if (L <= R) ans += R - L + 1;
        }
    }
    else ans = N * N;
    cout << ans << endl;
}
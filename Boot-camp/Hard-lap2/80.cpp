#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, K;
    cin >> N >> K;

    int64_t ans = 0;
    for (int64_t b = 1; b <= N; b++) {
        if (K >= b) continue;
        int64_t n_per_loop = b - K;
        ans += n_per_loop * N / b;
        if (K > 0) ans += max((int64_t)0, N % b - K + 1);
    }

    cout << ans << endl;
}
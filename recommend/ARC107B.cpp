#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int64_t ans = 0;
    for (int n = 2; n <= 2 * N; n++) {
        int m = n - K;
        if (2 <= m && m <= 2 * N) {
            ans += (max(1, n - N) - min(n - 1, N) + 1) * (max(1, m - N) - min(m - 1, N) + 1);
        }
    }
    cout << ans << endl;
}
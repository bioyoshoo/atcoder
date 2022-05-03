#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, H;
    cin >> N >> H;
    int64_t a_max = 0;
    vector<int64_t> B(N);
    for (int i = 0; i < N; i++) {
        int64_t a, b;
        cin >> a >> b;
        a_max = max(a_max, a);
        B.at(i) = b;
    }
    sort(B.rbegin(), B.rend());

    int64_t ans = 0;
    for (int i = 0; i < N; i++) {
        if (B[i] <= a_max) break;
        H -= B[i];
        ans++;
        if (H <= 0) break;
    }
    if (H > 0) ans += (H + a_max - 1) / a_max;
    cout << ans << endl;
}
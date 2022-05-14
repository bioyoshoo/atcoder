#include <bits/stdc++.h>
using namespace std;
const int64_t MAX = 1e8;

int main() {
    int64_t L, R;
    cin >> L >> R;

    R = min(R, L + 2019);
    int64_t ans = MAX;
    for (int64_t l = L; l <= R; l++) {
        for (int64_t r = l + 1; r <= R; r++) {
            int64_t cand = (l % 2019) * (r % 2019) % 2019;
            ans = min(ans, cand);
            if (cand == 0) break;
        }
    }

    cout << ans << endl;
}
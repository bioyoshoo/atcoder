#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t L, R;
    cin >> L >> R;

    R = min(R, L + 2019);
    int64_t ans = 1e7;
    for (int l = L; l <= R; l++) {
        for (int r = l + 1; r <= R; r++) {
            int64_t cand = (l % 2019) * (r % 2019) % 2019;
            ans = min(ans, cand);
            if (ans == 0) goto OUT;
        }
    }
OUT:
    cout << ans << endl;
}
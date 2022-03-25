#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, x;
    cin >> N >> x;
    vector<int64_t> Box(N);
    for (int i = 0; i < N; i++) cin >> Box.at(i);

    if (N == 2) {
        int64_t sum = Box.at(0) + Box.at(1);
        int64_t need = max((int64_t)0, sum - x);
        cout << need << endl;
    }
    else {
        int64_t ans = 0;
        for (int i = 0; i + 1 < N; i++) {
            int64_t sum = Box.at(i) + Box.at(i + 1);

            if (sum > x) {
                int64_t need = sum - x;
                int64_t res = max((int64_t)0, need - Box.at(i + 1));
                Box.at(i + 1) = max((int64_t)0, Box.at(i + 1) - need);
                need -= res;
                Box.at(i) -= need;
                ans += need;
            }
        }

        cout << ans << endl;
    }
}
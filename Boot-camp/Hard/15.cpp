#include <bits/stdc++.h>
using namespace std;
const int64_t INF = 1e10;

void chmin(int64_t &a, int64_t b) {
    if (a > b) a = b;
    return;
}

int main() {
    int N;
    cin >> N;
    vector<int64_t> A(N);
    int cnt_negative = 0;
    int64_t A_abs_min = INF, abs_sum = 0;
    for (int i = 0; i < N; i++) {
        int64_t a;
        cin >> a;
        if (a < 0) cnt_negative++;
        chmin(A_abs_min, abs(a));
        abs_sum += abs(a);
    }

    if (cnt_negative % 2 == 0) cout << abs_sum << endl;
    else cout << abs_sum - 2 * A_abs_min << endl;
}
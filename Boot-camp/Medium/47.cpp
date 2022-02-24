#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, P;
    cin >> N >> P;

    vector<int64_t> A(N + 1, 0);
    for (int i = 0; i < N; i++) cin >> A.at(i);

    vector<vector<int64_t>> dp(N + 1, vector<int64_t>(2, 0));
    dp.at(0) = { 1, 0 };

    for (int i = 0; i < N; i++) {
        if (A.at(i) % 2 == 0) {
            dp.at(i + 1).at(0) += 2 * dp.at(i).at(0);
            dp.at(i + 1).at(1) += 2 * dp.at(i).at(1);
        }
        else {
            dp.at(i + 1).at(0) += dp.at(i).at(0) + dp.at(i).at(1);
            dp.at(i + 1).at(1) += dp.at(i).at(0) + dp.at(i).at(1);
        }
    }

    if (P == 0) cout << dp.at(N).at(0) << endl;
    else cout << dp.at(N).at(1) << endl;
}
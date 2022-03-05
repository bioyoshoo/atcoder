#include <bits/stdc++.h>
using namespace std;
const int64_t mod = 998244353;

int main() {
    int64_t N;
    cin >> N;

    vector<vector<int64_t>> dp(N, vector<int64_t>(9, 0));
    dp.at(0) = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 9; j++) {
            dp.at(i).at(j) += dp.at(i - 1).at(j);
            dp.at(i).at(j) %= mod;
            
            if (j - 1 >= 0) {
                dp.at(i).at(j) += dp.at(i - 1).at(j - 1);
                dp.at(i).at(j) %= mod;
            }
            if (j + 1 <= 8) {
                dp.at(i).at(j) += dp.at(i - 1).at(j + 1);
                dp.at(i).at(j) %= mod;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 9; i++) {
        ans += dp.at(N - 1).at(i);
        ans %= mod;
    }

    cout << ans << endl;
}
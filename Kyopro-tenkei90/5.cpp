#include <bits/stdc++.h>
using namespace std;

bool check_spell(string S, vector<char> C) {
    for (char s: S) {
        bool flag = false;
        for (char c: C) {
            if (s == c) flag = true;
        }
        if (!flag) {
            return false;
        }
    }
    return true;
}

int main() {
    int64_t N, B, K;
    cin >> N >> B >> K;
    vector<int> C(K);
    for (int i = 0; i < K; i++) cin >> C.at(i);
    int64_t mod = pow(10, 9) + 7;

    vector<vector<int64_t>> dp(N + 1, vector<int64_t>(B, 0));
    dp.at(0).at(0) = 1;

    for (int64_t i = 0; i < N; i++) {
        for (int64_t j = 0; j < B; j++) {
            for (int k = 0; k < K; k++) {
                int64_t nex = (10 * j + C.at(k)) % B;
                dp.at(i + 1).at(nex) += dp.at(i).at(j);
                dp.at(i + 1).at(nex) %= mod;
            }
        }
    }

    cout << dp.at(N).at(0) << endl;
}
#include <bits/stdc++.h>
using namespace std;

void chmin(int64_t &a, int64_t b) {
    if (a > b) a = b;
    return;
}

int main() {
    int T;
    cin >> T;
    vector<int64_t> ans(T);

    for (int i = 0; i < T; i++) {
        int64_t N, A, B, X, Y, Z;
        cin >> N >> A >> B >> X >> Y >> Z;

        vector<tuple<int64_t, int64_t, int64_t>> choice;
        int64_t n = lcm(A, B);
        choice.push_back({X * n, 1, X});
        choice.push_back({Y * n / A, A, Y});
        choice.push_back({Z * n / B, B, Z});
        sort(choice.begin(), choice.end());

        int64_t cost = 0;
        int64_t point = 0;
        vector<int64_t> cand;
        for (int j = 0; j < 3; j++) {
            // first
            int64_t perform, p, c;
            tie(perform, p, c) = choice.at(j);
            int64_t step = (N - point) / p;
            point += p * step;
            cost += c * step;

            if (point == N) {
                cand.push_back(cost);
                continue;
            }

            // 残りdp
            vector<int64_t> dp(N - point + 1, 0);
            for (int k = 0; k < N - point + 1; k++) {
                for (int l = 0; l < 3; l++) {
                    int64_t dp_p, dp_c;
                    tie(ignore, dp_p, dp_c) = choice.at(l);
                    if (k + dp_p > N) continue;
                    chmin(dp.at(k + dp_p), dp.at(k) + dp_c);
                }
            }

            cand.push_back(dp[N - point]);
        }

        sort(cand.begin(), cand.end());
        ans[i] = cand[0];
    }

    for (int i = 0; i < T; i++) cout << ans[i] << endl;
}
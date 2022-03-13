#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e4;
const int64_t INF = 1e10;

void chmin(int64_t &a, int64_t b) {
    if (a > b) a = b;
    return;
}

int main() {
    int H, N;
    cin >> H >> N;
    vector<int64_t> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A.at(i) >> B.at(i);

    vector<int64_t> dp(MAX + 1, INF);
    dp.at(0) = 0;

    for (int h = 0; h < H; h++) {
        for (int i = 0; i < N; i++) {
            chmin(dp.at(h + A.at(i)), dp.at(h) + B.at(i));
        }
    }

    int64_t ans = INF;
    for (int64_t i = H; i <= MAX; i++) {
        if (dp.at(i) > 0) chmin(ans, dp.at(i));
    }

    cout << ans << endl;
}
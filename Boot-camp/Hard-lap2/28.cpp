#include <bits/stdc++.h>
using namespace std;

void chmin(int64_t &a, int64_t b) {
    if (a > b) a = b;
    return;
}

int main() {
    int64_t N, K;
    cin >> N >> K;
    vector<int64_t> X(N);
    for (int i = 0; i < N; i++) cin >> X.at(i);
    vector<int64_t> dist(N);
    for (int i = 0; i < N; i++) dist.at(i) = X.at(i) - X.at(0);

    int64_t ans = 1e15;
    for (int i = 0; i < N; i++) {
        if (i + K - 1 >= N) continue;
        int64_t cand1 = abs(X.at(i)) + (dist.at(i + K - 1) - dist.at(i));
        int64_t cand2 = abs(X.at(i + K - 1)) + (dist.at(i + K - 1) - dist.at(i));
        chmin(ans, cand1);
        chmin(ans, cand2);
    }

    cout << ans << endl;
}
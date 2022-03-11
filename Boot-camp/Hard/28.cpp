#include <bits/stdc++.h>
using namespace std;
const int64_t MAX = 1e15;

template<class T> void chmin(T &a, T b) {
    if (a > b) a = b;
    return;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int64_t> X(N);
    for (int i = 0; i < N; i++) cin >> X.at(i);

    int64_t ans = MAX;
    for (int i = 0; i + K - 1 < N; i++) {
        int64_t intervals = abs(X.at(i) - X.at(i + K - 1));
        int64_t near_edge = min(abs(X.at(i)), abs(X.at(i + K - 1)));
        chmin(ans, near_edge + intervals);
    }

    cout << ans << endl;
}
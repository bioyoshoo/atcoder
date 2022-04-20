#include <bits/stdc++.h>
using namespace std;
const int64_t MAX = 1e15;

void chmin(int64_t &a, int64_t b) {
    if (a > b) a = b;
    return;
}

int main() {
    int64_t N;
    cin >> N;
    vector<int64_t> A(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);
    for (int i = 1; i < N; i++) A.at(i) += A.at(i - 1);

    int64_t ans = MAX;
    for (int i = 0; i < N - 1; i++) {
        int64_t x = A.at(i), y = A.at(N - 1) - A.at(i);
        chmin(ans, abs(x - y));
    }

    cout << ans << endl;
}
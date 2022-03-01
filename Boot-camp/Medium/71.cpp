#include <bits/stdc++.h>
using namespace std;

void chmin(int64_t &a, int64_t b) {
    if (a > b) a = b;
    return;
}

int main() {
    int N;
    cin >> N;
    vector<int64_t> A(N), C(N);
    int64_t sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
        C.at(i) = sum + A.at(i);
        sum = C.at(i);
    }

    int64_t ans = 1e15;
    for (int i = 0; i <= N - 2; i++) chmin(ans, abs(2 * C.at(i) - C.at(N - 1)));
    cout << ans << endl;
}
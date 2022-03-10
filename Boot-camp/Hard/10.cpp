#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, K;
    cin >> N >> K;
    vector<int64_t> A(N);
    for (int64_t i = 0; i < N; i++) cin >> A.at(i);

    int64_t right = 0, sum = 0, ans = 0;
    for (int64_t left = 0; left < N; left++) {
        while (right < N && sum < K) {
            sum += A.at(right);
            right++;
        }
        if (sum < K) break;

        ans += N - right + 1;

        if (left == right) right++;
        sum -= A.at(left);
    }

    cout << ans << endl;
}
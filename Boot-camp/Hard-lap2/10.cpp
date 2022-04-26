#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, K;
    cin >> N >> K;
    vector<int64_t> A(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);

    int64_t ans = 0, sum = 0;
    int right = 0;
    for (int left = 0; left < N; left++) {
        while (right < N && sum < K) {
            sum += A[right];
            right++;
        }
        if (sum >= K) ans += N - right + 1;

        if (left == right) right++;
        sum -= A[left];
    }

    cout << ans << endl;
}
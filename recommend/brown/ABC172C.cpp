#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, M, K;
    cin >> N >> M >> K;
    vector<int64_t> A(N + 1), B(M + 1);
    for (int i = 1; i < N + 1; i++) cin >> A.at(i);
    for (int i = 1; i < N + 1; i++) A[i] += A[i - 1];
    for (int i = 1; i < M + 1; i++) cin >> B.at(i);
    for (int i = 1; i < M + 1; i++) B[i] += B[i - 1];

    int64_t ans = 0;
    int64_t b = M;
    for (int64_t a = 0; a <= N; a++) {
        while (b > 0 && A[a] + B[b] > K) b--;
        if (A[a] + B[b] <= K) ans = max(ans, a + b);
    }

    cout << ans << endl;
}
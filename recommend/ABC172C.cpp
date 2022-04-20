#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, M, K;
    cin >> N >> M >> K;
    vector<int64_t> A(N + 1, 0), B(M + 1, 0);
    for (int i = 1; i <= N; i++) cin >> A.at(i);
    for (int i = 1; i <= M; i++) cin >> B.at(i);

    for (int i = 1; i < N + 1; i++) A.at(i) += A.at(i - 1);
    for (int i = 1; i < M + 1; i++) B.at(i) += B.at(i - 1);

    int64_t ans = 0;
    int64_t j = M;
    for (int64_t a = 0; a <= N; a++) {
        if (j > 0 && A[a] + B[j] > K) j--;
        if (A[a] + B[j] <= K) ans = max(ans, a + j);
    }

    cout << ans << endl;
}
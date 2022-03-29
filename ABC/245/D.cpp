#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, M;
    cin >> N >> M;
    vector<int64_t> A(N + 1), B(M + 1, 0), C(N + M + 1);
    for (int i = 0; i <= N; i++) cin >> A.at(i);
    for (int i = 0; i <= N + M; i++) cin >> C.at(i);

    // cの係数 n次の係数について
    for (int i = M; i >= 0; i--) {
        B[i] = C[i + N] / A[N];
        for (int j = 0; j <= N; j++) {
            C[i + j] -= B[i] * A[j];
        }
    }
    for (int i = 0; i < M + 1; i++) cout << B.at(i) << " ";
    cout << endl;
}
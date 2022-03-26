#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, M;
    cin >> N >> M;
    vector<int64_t> A(N + 1), B(M + 1, 0), C(N + M + 1);
    for (int i = 0; i <= N; i++) cin >> A.at(i);
    for (int i = 0; i <= N + M; i++) cin >> C.at(i);

    
    // cの係数 n次の係数について
   for (int64_t n = N + M; n >= N - 1; n--) {
        // aの係数を固定
        int64_t sum = 0;
        for (int64_t b = n - 1; b >= 0; b--) {
            int64_t a = n - b;
            if (a > N) continue;
            sum += A.at(a) * B.at(b);
        }
        B.at(n - N) = (C.at(n) - sum) / A.at(n - N);
    }
    for (int i = 0; i < M + 1; i++) cout << B.at(i) << " ";
    cout << endl;
}
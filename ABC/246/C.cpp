#include <bits/stdc++.h>
using namespace std;
const int64_t MAX = 1e10;

int main() {
    int64_t N, K, X;
    cin >> N >> K >> X;
    vector<int64_t> A(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);

    for (int i = 0; i < N; i++) {
        int64_t discount;
        discount = min(A.at(i) / X, K);
        if (discount > 0) A.at(i) -= discount * X;
        K -= discount;
    }

    if (K > 0) {
        sort(A.rbegin(), A.rend());

        for (int i = 0; i < N; i++) {
            A.at(i) = max((int64_t)0, A.at(i) - X);
            K--;
            if (K == 0) break;
        }
    }

    int64_t ans = 0;
    for (int i = 0; i < N; i++) ans += A.at(i);

    cout << ans << endl;
}
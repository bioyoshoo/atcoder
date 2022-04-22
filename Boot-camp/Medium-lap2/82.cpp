#include <bits/stdc++.h>
using namespace std;

int64_t mse(vector<int64_t> V, int64_t x) {
    int64_t res = 0;
    for (int64_t v: V) res += (v - x) * (v - x);
    return res;
}

int main() {
    int N;
    cin >> N;
    vector<int64_t> A(N);
    int64_t sum = 0;
    for (int i = 0; i < N; i++) {
        int64_t a;
        cin >> a;
        sum += a;
        A.at(i) = a;
    }

    int64_t cand1 = sum / N, cand2 = sum / N + 1;
    int64_t ans = min(mse(A, cand1), mse(A, cand2));
    cout << ans << endl;
}
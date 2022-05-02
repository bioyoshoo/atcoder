#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    cin >> N;
    vector<int64_t> A(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);
    for (int i = 0; i < N; i++) A.at(i) -= i + 1;
    sort(A.begin(), A.end());

    int64_t b;
    int64_t ans = 0;
    if (N % 2 == 1) {
        b = A.at(N / 2);
        for (int i = 0; i < N; i++) ans += abs(A.at(i) - b);
    }
    else {
        int64_t b1, b2;
        b1 = (A.at(N / 2 - 1) + A.at(N / 2)) / 2;
        b2 = b1 + 1;
        int64_t cand1 = 0, cand2 = 0;
        for (int i = 0; i < N; i++) {
            cand1 += abs(A.at(i) - b1);
            cand2 += abs(A.at(i) - b2);
        }
        ans = min(cand1, cand2);
    }
    cout << ans << endl;
}
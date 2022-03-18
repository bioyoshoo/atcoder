#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int64_t> A(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);
    for (int i = 0; i < N; i++) A.at(i) -= i + 1;

    sort(A.begin(), A.end());

    int64_t ans = 0;
    if (N % 2 == 1) {
        int64_t b = A.at(N / 2);
        for (int i = 0; i < N; i++) ans += abs(A.at(i) - b);
    }
    else if (N % 2 == 0) {
        int64_t b = (A.at(N / 2 - 1) + A.at(N / 2)) / 2;
        for (int i = 0; i < N; i++) ans += abs(A.at(i) - b);
    }

    cout << ans << endl;
}
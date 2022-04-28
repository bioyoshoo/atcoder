#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    cin >> N;
    vector<int64_t> A(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);
    sort(A.begin(), A.end());

    int idx = 0;
    int64_t sum = 0;
    for (int i = 0; i < N - 1; i++) {
        sum += A[i];
        if (2 * sum < A[i + 1]) idx = i + 1;
    }
    int64_t ans = N - idx;
    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    cin >> N;
    vector<int64_t> A(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);

    int64_t even = 0, odd = 0;
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) even += A[i];
        else odd += A[i];
    }
    vector<int64_t> ans(N);
    ans[0] = (even - odd) / 2;
    for (int i = 1; i < N; i++) ans[i] = A[i - 1] - ans[i - 1];
    for (int i = 0; i < N; i++) cout << ans[i] * 2 << " ";
    cout << endl;
}
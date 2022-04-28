#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int64_t> A(n);
    for (int i = 0; i < n; i++) cin >> A.at(i);
    sort(A.rbegin(), A.rend());

    int64_t ans_1, ans_2;
    ans_1 = A[0];
    int64_t min_diff = 1e10;
    for (int i = 1; i < n; i++) {
        int64_t diff = abs(A[i] - ans_1 / 2);
        if (diff < min_diff) {
            min_diff = diff;
            ans_2 = A[i];
        }
    }

    cout << ans_1 << " " << ans_2 << endl;
}
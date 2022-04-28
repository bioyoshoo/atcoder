#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t K, T;
    cin >> K >> T;
    vector<int64_t> A(T);
    for (int i = 0; i < T; i++) cin >> A.at(i);
    sort(A.rbegin(), A.rend());

    int64_t max_n = A.at(0), others = 0;
    for (int i = 1; i < T; i++) others += A[i];
    int64_t ans = max((int64_t)0, max_n - others - 1);
    cout << ans << endl;
}
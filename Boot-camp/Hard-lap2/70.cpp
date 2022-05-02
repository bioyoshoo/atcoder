#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    cin >> N;
    vector<int64_t> A(N), B(N), C(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);
    for (int i = 0; i < N; i++) cin >> B.at(i);
    for (int i = 0; i < N; i++) cin >> C.at(i);
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    int64_t ans = 0;
    for (int i = 0; i < N; i++) {
        int a_ind = lower_bound(A.begin(), A.end(), B.at(i)) - A.begin();
        int c_ind = upper_bound(C.begin(), C.end(), B.at(i)) - C.begin();
        ans += a_ind * (N - c_ind);
    }
    cout << ans << endl;
}
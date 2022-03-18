#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int64_t> A(N), B(N), C(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);
    for (int i = 0; i < N; i++) cin >> B.at(i);
    for (int i = 0; i < N; i++) cin >> C.at(i);

    sort(A.begin(), A.end());
    sort(C.begin(), C.end());

    int64_t ans = 0;
    for (int i = 0; i < N; i++) {
        int64_t cand_a, cand_c;
        cand_a = lower_bound(A.begin(), A.end(), B.at(i)) - A.begin();
        cand_c = C.end() - upper_bound(C.begin(), C.end(), B.at(i));
        ans += cand_a * cand_c;
    }

    cout << ans << endl;
}
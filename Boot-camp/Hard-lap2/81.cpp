#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, x;
    cin >> N >> x;
    vector<int64_t> A(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);

    int64_t ans = 0;
    for (int i = 0; i < N - 1; i++) {
        int64_t sum = A.at(i) + A.at(i + 1);
        if (sum > x) {
            int64_t diff = sum - x;
            int64_t sub = min(A.at(i + 1), diff);
            A.at(i + 1) -= sub;
            diff -= sub;
            A.at(i) -= diff;
            ans += sum - x;
        }
    }

    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int64_t> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A.at(i) >> B.at(i);

    int64_t ans = 0;
    for (int i = N - 1; i >= 0; i--) {
        int64_t new_a = A.at(i) + ans;
        int64_t time = 0;
        if (new_a % B.at(i) != 0) time = B.at(i) - new_a % B.at(i);
        ans += time;
    }

    cout << ans << endl;
}
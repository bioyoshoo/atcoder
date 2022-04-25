#include <bits/stdc++.h>
using namespace std;
const int64_t M = 2e5;

int main() {
    int64_t N;
    cin >> N;
    map<int64_t, int64_t> A;
    for (int i = 0; i < N; i++) {
        int64_t a;
        cin >> a;
        A[a]++;
    }

    int64_t ans = 0;
    for (int64_t a = 1; a <= M; a++) {
        for (int64_t b = 1; b <= M / a; b++) {
            int64_t c = a * b;
            ans += A[a] * A[b] * A[c];
        }
    }

    cout << ans << endl;
}
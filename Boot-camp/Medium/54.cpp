#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, C, K;
    cin >> N >> C >> K;
    vector<int64_t> T(N);
    for (int64_t i = 0; i < N; i++) cin >> T.at(i);
    sort(T.begin(), T.end());

    int64_t ans = 1, n = 0, limit = 0;
    for (int64_t i = 0; i < N; i++) {
        if (n == 0) {
            n++;
            limit = T.at(i) + K;
        }
        else if (n < C && T.at(i) <= limit) n++;
        else if (n < C && T.at(i) > limit) {
            ans++;
            n = 1;
            limit = T.at(i) + K;
        }
        
        if (n == C && i < N - 1) {
            ans++;
            n = 0;
        }
    }

    cout << ans << endl;
}
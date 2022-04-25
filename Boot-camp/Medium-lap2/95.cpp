#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, K;
    cin >> N >> K;
    vector<pair<int64_t, int64_t>> seq(N);
    for (int i = 0; i < N; i++) {
        int64_t a, b;
        cin >> a >> b;
        seq.at(i) = {a, b};
    }
    sort(seq.begin(), seq.end());

    int64_t ans;
    for (int i = 0; i < N; i++) {
        int64_t a, b;
        tie(a, b) = seq.at(i);
        K -= b;
        if (K <= 0) {
            ans = a;
            break;
        }
    }

    cout << ans << endl;
}
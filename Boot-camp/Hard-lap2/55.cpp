#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, A, B;
    cin >> N >> A >> B;
    vector<int64_t> V(N);
    for (int i = 0; i < N; i++) cin >> V.at(i);

    int64_t ans = 0;
    for (int i = 0; i < N - 1; i++) {
        int64_t walk = A * (V[i + 1] - V[i]);
        if (walk <= B) ans += walk;
        else ans += B;
    }

    cout << ans << endl;
}
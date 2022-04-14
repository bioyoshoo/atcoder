#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, X;
    cin >> N >> X;
    vector<int64_t> V(N);
    for (int i = 0; i < N; i++) {
        int64_t x;
        cin >> x;
        V.at(i) = abs(X - x);
    }

    int64_t ans = V.at(0);
    for (int i = 1; i < N; i++) ans = gcd(ans, V.at(i));

    cout << ans << endl;
}
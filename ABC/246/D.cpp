#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    cin >> N;

    vector<int64_t> X;
    for (int64_t a = 1; a <= 1e6; a++) {
        for (int64_t b = 1e6 / a; b >= 0; b--) {
            X.push_back(a*a*a + a*a*b + a*b*b + b*b*b);
        }
    }

    sort(X.begin(), X.end());

    int64_t ans = *lower_bound(X.begin(), X.end(), N);

    cout << ans << endl;
}
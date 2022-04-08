#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, K;
    cin >> N >> K;

    long double ans = 0;
    for (int n = 1; n <= N; n++) {
        int j = 0;
        while (n * pow(2, j) < K) j++;

        long double p = pow(0.5, j);
        ans += p;
    }
    ans /= N;

    cout << fixed << setprecision(12);
    cout << ans << endl;
}
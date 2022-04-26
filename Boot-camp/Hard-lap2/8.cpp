#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    cin >> N;

    int64_t ans = 0;
    if (N % 2 == 0) {
        int64_t a = 2;
        while (a < N) {
            a *= 5;
            ans += N / a;
        }
    }

    cout << ans << endl;
}
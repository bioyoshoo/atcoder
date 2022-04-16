#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t A, B, K;
    cin >> A >> B >> K;

    int64_t ans = 0;
    int64_t n = A;
    while (n < B) {
        n *= K;
        ans++;
    }

    cout << ans << endl;
}
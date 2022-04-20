#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int64_t a0;
    cin >> a0;
    int64_t ans = a0;
    for (int i = 1; i < N; i++) {
        int64_t a;
        cin >> a;
        ans = gcd(ans, a);
    }

    cout << ans << endl;
}
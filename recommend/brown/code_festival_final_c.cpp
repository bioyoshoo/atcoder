#include <bits/stdc++.h>
using namespace std;

int main() {
    long long A;
    cin >> A;

    bool flag = false;
    long long ans;
    for (long long k = 10; k <= 1e4; k++) {
        long long n = k, a = 0, b = 1;
        while (n > 0) {
            int res = n % 10;
            a += res * b;
            b *= k;
            n /= 10;
        }
        if (a == A) {
            ans = k;
            flag = true;
            break;
        }
    }
    if (flag) cout << ans << endl;
    else cout << -1 << endl;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int A, B; cin >> A >> B;

    int ans = -1;
    for (int x = 1; x <= 1e5; x++) {
        if (x * 8 / 100 == A && x * 10 / 100 == B) {
            ans = x;
            break;
        }
    }
    cout << ans << endl;
}
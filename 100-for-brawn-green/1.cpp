#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    while (true) {
        int n, x; cin >> n >> x;
        if (n == 0 && x == 0) break;
        
        int ans = 0;
        for (int a = 1; a <= n; a++) {
            for (int b = a + 1; b <= n; b++) {
                int c = x - a - b;
                if (b < c && c <= n) ans++;
            }
        }
        cout << ans << endl;
    }
}
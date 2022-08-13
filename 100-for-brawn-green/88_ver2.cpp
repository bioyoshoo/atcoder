#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    stack<int> sk;

    int prev_c = -1;
    rep(i, N) {
        int c; cin >> c;
        if (c != prev_c) {
            if (i % 2 == 0) {
                // odd
                sk.push(i);
            }
            else {
                // even
                if (sk.top() != 0) sk.pop();
            }
        }
        prev_c = c;
    }

    int ans = 0;
    int prev_a = N;
    int c = prev_c;
    while (!sk.empty()) {
        int a = sk.top();
        if (c == 0) ans += prev_a - a;
        c = 1 - c;
        prev_a = a;
        sk.pop();
    }
    cout << ans << endl;
}
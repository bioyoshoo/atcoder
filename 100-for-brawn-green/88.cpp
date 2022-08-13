#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    stack<pair<int, int>> sk;
    int cnt = 1;

    rep(i, N) {
        int c; cin >> c;

        if (sk.empty()) sk.push({c, 1});
        else {
            int prev_c, prev_n;
            tie(prev_c, prev_n) = sk.top();
            sk.pop();

            if (cnt == 0) {
                if (c == prev_c) sk.push({c, prev_n + 1});
                else {
                    if (!sk.empty()) {
                        int prev_prev_c, prev_prev_n;
                        tie(prev_prev_c, prev_prev_n) = sk.top();
                        
                        if (c == prev_prev_c) {
                            sk.pop();
                            sk.push({c, prev_prev_n + prev_n + 1});
                        }
                        else sk.push({c, prev_n + 1});
                    }
                    else sk.push({c, prev_n + 1});
                }
            }
            else {
                if (c == prev_c) sk.push({c, prev_n + 1});
                else {
                    sk.push({prev_c, prev_n});
                    sk.push({c, 1});
                }
            }
        }
        cnt = 1 - cnt;
    }
    int ans = 0;
    while (!sk.empty()) {
        int c, n;
        tie(c, n) = sk.top();
        if (c == 0) ans += n;
        sk.pop();
    }
    cout << ans << endl;
}
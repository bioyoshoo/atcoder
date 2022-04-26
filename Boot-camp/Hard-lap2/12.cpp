#include <bits/stdc++.h>
using namespace std;
const int64_t mod = 998244353;

int main() {
    int64_t N;
    cin >> N;
    vector<int64_t> D(N), depth(N, 0);
    int64_t max_d = 0;
    for (int i = 0; i < N; i++) {
        cin >> D.at(i);
        depth[D[i]]++;
        max_d = max(max_d, D[i]);
    }
    // root 1
    if (depth[0] == 1 && D[0] == 0) {
        vector<int64_t> ans(N, 0);
        ans[0] = 1;
        for (int i = 1; i < N; i++) {
            if (depth[i - 1] == 0 || depth[i] == 0) ans[i] = 0;
            else {
                int64_t a = 1;
                for (int r = 0; r < depth[i]; r++) a = a * depth[i - 1] % mod;
                ans[i] = ans[i - 1] * a % mod;
            }
        }
        cout << ans[max_d] << endl;
    }
    else cout << 0 << endl;
}
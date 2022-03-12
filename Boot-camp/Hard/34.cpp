#include <bits/stdc++.h>
using namespace std;
const int64_t mod = 1e9 + 7;

int main() {
    int N;
    cin >> N;
    vector<int> V(N, 0);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        V.at(a)++;
    }

    int64_t ans = 1;
    bool flag = true;
    if (N % 2 == 0) {
        for (int i = 1; i < N; i += 2) {
            if (V.at(i) != 2) {
                flag = false;
                break;
            }
            else {
                ans *= V.at(i);
                ans %= mod;
            }
        }
    }
    else if (N % 2 == 1) {
        for (int i = 0; i < N; i += 2) {
            if ((i == 0 && V.at(0) != 1) || (i > 0 && V.at(i) != 2)) {
                flag = false;
                break;
            }
            else {
                ans *= V.at(i);
                ans %= mod;
            }
        }
    }

    if (!flag) cout << 0 << endl;
    else cout << ans << endl;
}

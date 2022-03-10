#include <bits/stdc++.h>
using namespace std;
const int64_t mod =  998244353;

int main() {
    int N;
    cin >> N;
    map<int, int> M;
    int max_d = -1;
    for (int i = 0; i < N; i++) {
        int d;
        cin >> d;
        M[d]++;
        max_d = max(max_d, d);
    }

    vector<int> D(max_d + 1, 0);
    for (auto m: M) D.at(m.first) = m.second;

    bool flag = true;
    if (D.at(0) != 1) flag = false;
    else {
        for (int i = 1; i <= max_d; i++) {
            if (D.at(i) == 0) {
                flag = false;
                break;
            }
        }
    }

    if (!flag) cout << 0 << endl;
    else {
        int64_t ans = 1;
        for (int i = 1; i <= max_d; i++) {
            for (int j = 0; j < D.at(i); j++) {
                ans *= D.at(i - 1) % mod;
            }
        }

        cout << ans << endl;
    }
}
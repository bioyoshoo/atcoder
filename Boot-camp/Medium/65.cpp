#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    string S, T;
    cin >> S >> T;

    if (N > M) {
        swap(N, M);
        swap(S, T);
    }

    int64_t ans;
    if (lcm(N, M) == M) {
        bool flag = true;
        for (int i = 0; i < N; i++) {
            if (S.at(i) != T.at(gcd(N, M) * i)) {
                flag = false;
                break;
            }
        }
        if (flag) ans = M;
        else ans = -1;
    }
    else {
        if (S.at(0) == T.at(0)) ans = lcm(N, M);
        else ans = -1;
    }

    cout << ans << endl;
}
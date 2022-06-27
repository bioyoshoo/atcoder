#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, K, Q; cin >> N >> K >> Q;
    vector<int> A(K);
    rep(i, K) {
        cin >> A[i];
        A[i]--;
    }
    vector<int> L(Q); rep(i, Q) cin >> L[i];

    vector<int> state(N);
    rep(i, K) state[A[i]] = 1;

    rep(i, Q) {
        int cnt = 0;
        int pos;
        rep(j, N) {
            if (state[j] == 1) {
                cnt += 1;
                if (cnt == L[i]) {
                    pos = j;
                    break;
                }
            }
        }

        if (pos == N - 1) continue;
        else {
            if (state[pos + 1] == 0) {
                state[pos] = 0;
                state[pos + 1] = 1;
            }
        }
    }

    rep(i, N) if (state[i] == 1) cout << i + 1 << " ";
    cout << endl;
}
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, Q; cin >> N >> Q;
    vector<int> A(N); rep(i, N) A[i] = i + 1;

    int rev = 0;
    rep(i, Q) {
        int q; cin >> q;
        if (q == 1) {
            int x, y; cin >> x >> y; x--;

            if (rev == 0) {
                A[x] = y;
            }
            else if (rev == 1) {
                A[N - x - 1] = y;
            }
        }
        else if (q == 2) {
            rev = 1 - rev;
        }
        else if (q == 3) {
            int x; cin >> x; x--;

            if (rev == 0) {
                cout << A[x] << endl;
            }
            else if (rev == 1) {
                cout << A[N - x - 1] << endl;
            }
        }
    }
}

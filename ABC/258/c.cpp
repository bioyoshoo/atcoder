#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, Q; cin >> N >> Q;
    string S; cin >> S;

    int point = 0;
    rep(i, Q) {
        int t, x; cin >> t >> x;
        if (t == 1) {
            int d_to_zero = point;
            if (x <= d_to_zero) {
                point -= x;
            }
            else {
                x -= d_to_zero + 1;
                point = N - 1;
                point -= x;
            }
        }
        else if (t == 2) {
            x--;
            cout << S[(point + x) % N] << endl;
        }
    }
}
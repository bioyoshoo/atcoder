#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    int max_h = -1, ans = -1;
    rep(i, N) {
        int H; cin >> H;
        if (max_h < H) {
            max_h = H;
            ans = i;
        }
    }

    cout << ans + 1 << endl;
}
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int T; cin >> T;
    rep(t, T) {
        int N; cin >> N;
        int cnt = 0;
        rep(i, N) {
            int a; cin >> a;
            if (a % 2 == 1) cnt++;
        }
        cout << cnt << endl;
    }
}
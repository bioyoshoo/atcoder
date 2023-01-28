#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    string S, T; cin >> S >> T;
    int N = T.size();

    int ans = -1;
    int cur = 0;
    rep(i, N) {
        if (S[cur] == T[i]) cur++;
        else {
            ans = i + 1;
            break;
        }
    }

    cout << ans << endl;
}

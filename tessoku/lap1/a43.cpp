#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, L; cin >> N >> L;
    int min_e = L + 1, max_w = -1;
    rep(i, N) {
        int a; char b; cin >> a >> b;
        if (b == 'E') min_e = min(min_e, a);
        else if (b == 'W') max_w = max(max_w, a);
    }

    int ans = 0;
    if (min_e != L + 1) ans = max(ans, L - min_e);
    if (max_w != -1) ans = max(ans, max_w);

    cout << ans << endl;
}
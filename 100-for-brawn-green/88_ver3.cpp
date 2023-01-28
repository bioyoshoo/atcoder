#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n; cin >> n;
    vector<int> V;

    int c = -1;
    rep(i, n) {
        int a; cin >> a;

        if (i == 0) V.push_back(0);
        else if ((i + 1) % 2 == 1) {
            if (c != a) V.push_back(i);
        }
        else {
            if (c != a) if (V.size() > 1) V.pop_back();
        }

        c = a;
    }
    V.push_back(n);

    int ans = 0;
    for (int i = (int)V.size() - 1; i >= 1; i--) {
        if (c == 0) ans += V[i] - V[i - 1];
        c = 1 - c;
    }

    cout << ans << endl;
}

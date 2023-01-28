#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const int INF = 300000;

int main() {
    vector<bool> isprime(INF + 1, true);
    isprime[0] = isprime[1] = false;

    for (int x = 2; x <= INF; x++) {
        if (!isprime[x]) continue;

        for (int y = 2 * x; y <= INF; y += x) isprime[y] = false;
    }

    int Q; cin >> Q;
    rep(i, Q) {
        int x; cin >> x;
        if (isprime[x]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}

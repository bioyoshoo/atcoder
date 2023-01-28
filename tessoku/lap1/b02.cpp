#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int A, B; cin >> A >> B;

    bool ans = false;
    for (int n = A; n <= B; n++) {
        if (100 % n == 0) ans = true;
    }

    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using mint = modint1000000007;

int main() {
    int N; cin >> N;

    mint A = -1, B = 1, C = 1;
    for (int i = 3; i <= N; i++) {
        A = B + C;
        C = B; B = A;
    }

    cout << A.val() << endl;
}

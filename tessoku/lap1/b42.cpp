#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int N;
ll A[100010], B[100010];

// head == 1: 表の合計が正, head == 2: 表の合計が負
// tail == 1: 裏の合計が正, tail == 2: 裏の合計が負
ll solve(int head, int tail) {
    ll sum = 0;
    rep(i, N) {
        ll card1 = A[i]; if (head == 2) card1 = -A[i];
        ll card2 = B[i]; if (tail == 2) card2 = -B[i];

        if (card1 + card2 > 0) sum += card1 + card2;
    }
    return sum;
}

int main() {
    cin >> N;
    rep(i, N) cin >> A[i] >> B[i];

    ll ans1 = solve(1, 1);
    ll ans2 = solve(1, 2);
    ll ans3 = solve(2, 1);
    ll ans4 = solve(2, 2);

    cout << max({ans1, ans2, ans3, ans4}) << endl;
}

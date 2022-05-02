#include <bits/stdc++.h>
using namespace std;

vector<int64_t> memo;
int64_t num_layers(int64_t level) {
    if (level == 0) return memo[0] = 1;
    if (memo[level] != -1) return memo[level];
    return memo[level] = 2 * num_layers(level - 1) + 3;
}

vector<int64_t> memo2;
int64_t num_all_p(int64_t level) {
    if (memo2[level] != -1) return memo2[level];
    if (level == 0) return memo2[level] = 1;
    return memo2[level] = 2 * num_all_p(level - 1) + 1;
}

int64_t rec(int64_t n, int64_t x) {
    if (n == 0 && x == 0) return 0;
    if (n == 0 && x >= 1) return 1;
    if (x <= 1) return 0;
    int64_t pre_layers = num_layers(n - 1);
    if (2 <= x && x <= pre_layers + 1) return rec(n - 1, x - 1);
    int64_t pre_all_p = num_all_p(n - 1);
    if (x == pre_layers + 2) return pre_all_p + 1;
    if (pre_layers + 2 < x && x <= 2 * pre_layers + 2) return pre_all_p + rec(n - 1, x - pre_layers - 2) + 1;
    if (2 * pre_layers + 2 <= x) return 2 * pre_all_p + 1;
}

int main() {
    int64_t N, X;
    cin >> N >> X;

    memo.assign(N + 1, -1);
    num_layers(N);
    memo2.assign(N + 1, -1);
    num_all_p(N);

    int64_t ans = rec(N, X);
    cout << ans << endl;
}
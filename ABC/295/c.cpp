#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    map<int, int> A;
    rep(i, N) {
        int a; cin >> a;
        A[a] += 1;
    }

    int ans = 0;
    for (auto a: A) {
        ans += a.second / 2;
    }
    cout << ans << endl;
}
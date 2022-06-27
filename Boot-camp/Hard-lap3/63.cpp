#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

set<int> st;
bool check(int n) {
    while (n > 0) {
        if (st.count(n % 10)) return false;
        n /= 10;
    }
    return true;
}

int main() {
    int N, K; cin >> N >> K;
    rep(i, K) {
        int k; cin >> k;
        st.insert(k);
    }
    int ans = N;
    while (!check(ans)) {
        ans++;
    }
    cout << ans << endl;
}
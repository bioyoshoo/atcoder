#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll N, X; cin >> N >> X;
    string S; cin >> S;

    stack<char> sk;
    for (int i = 0; i < N; i++) {
        if (!sk.empty() && S[i] == 'U' && (sk.top() == 'R' || sk.top() == 'L')) sk.pop();
        else sk.push(S[i]);
    }
    string T = "";
    while (!sk.empty()) {
        T += sk.top();
        sk.pop();
    }
    reverse(T.begin(), T.end());
    ll ans = X;
    for (auto t: T) {
        if (t == 'U') ans /= 2;
        else if (t == 'R') ans = 2 * ans + 1;
        else if (t == 'L') ans = 2 * ans;
    }
    cout << ans << endl;
}
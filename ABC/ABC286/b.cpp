#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    string S; cin >> S;
    stack<char> sk;
    
    rep(i, N) {
        if (S[i] == 'a') {
            if (!sk.empty() && sk.top() == 'n') {
                sk.push('y');
                sk.push('a');
            }
            else sk.push('a');
        }
        else sk.push(S[i]);
    }

    string ans = "";
    while (!sk.empty()) {
        ans += sk.top();
        sk.pop();
    }
    reverse(ans.begin(), ans.end());

    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    string S; cin >> S;
    string T = "atcoder";
    deque<char> deq;
    stack<char> sk;

    int ans = 0;
    rep(i, 7) deq.push_back(S[i]);
    rep(i, 7) {
        while (true) {
            char c = deq.front();
            deq.pop_front();
            if (c == T[i]) break;
            sk.push(c);
            ans++;
        }

        while (!sk.empty()) {
            char c = sk.top();
            deq.push_front(c);
            sk.pop();
        }
    }
    cout << ans << endl;
}
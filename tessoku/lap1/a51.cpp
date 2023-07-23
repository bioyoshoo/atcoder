#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int Q; cin >> Q;
    stack<string> sk;

    rep(i, Q) {
        int x; cin >> x;
        if (x == 1) {
            string S; cin >> S;
            sk.push(S);
        }
        else if (x == 2) {
            cout << sk.top() << endl;
        }
        else if (x == 3) {
            sk.pop();
        }
    }
}

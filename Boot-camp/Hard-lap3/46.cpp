#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    string X; cin >> X;
    int N = X.size();

    stack<char> sk;
    rep(i, N) {
        if (sk.empty()) sk.push(X[i]);
        else {
            if (sk.top() == 'S' && X[i] == 'T') sk.pop();
            else sk.push(X[i]);
        }
    }
    cout << sk.size() << endl;
}
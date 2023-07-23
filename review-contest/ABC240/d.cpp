#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    stack<pair<int, int>> sk;

    rep(i, N) {
        int a; cin >> a;

        if (sk.empty()) {
            sk.push(make_pair(a, 1));
            cout << sk.size() << endl;
            continue;
        }

        int prev, cnt; tie(prev, cnt) = sk.top();
        if (a == prev) {
            sk.push(make_pair(a, cnt + 1));

            if (a == cnt + 1) {
                while (!sk.empty() && sk.top().first == a) sk.pop();
            }
        }
        else {
            sk.push(make_pair(a, 1));
        }

        cout << sk.size() << endl;
    }
}

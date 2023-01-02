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

        while (!sk.empty() && sk.top().first <= a) {
            sk.pop();
        }

        if (sk.empty()) cout << -1 << " ";
        else cout << sk.top().second << " ";

        sk.push({a, i + 1});
    }

    cout << endl;
}

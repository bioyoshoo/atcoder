#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int Q; cin >> Q;
    queue<string> que;

    rep(i, Q) {
        int x; cin >> x;
        if (x == 1) {
            string s; cin >> s;
            que.push(s);
        }
        else if (x == 2) {
            cout << que.front() << endl;
        }
        else if (x == 3) {
            que.pop();
        }
    }
}

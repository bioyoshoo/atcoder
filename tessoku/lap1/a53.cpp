#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int Q; cin >> Q;
    priority_queue<int, vector<int>, greater<int>> pq;

    rep(i, Q) {
        int x; cin >> x;
        if (x == 1) {
            int p; cin >> p;
            pq.push(p);
        }
        else if (x == 2) {
            cout << pq.top() << endl;
        }
        else if (x == 3) {
            pq.pop();
        }
    }
}
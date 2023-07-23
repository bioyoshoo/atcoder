#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int Q; cin >> Q;
    deque<string> dq1, dq2;
    int n = 0;
    rep(i, Q) {
        char q; cin >> q;
        
        if (q == 'A') {
            string X; cin >> X;
            dq2.push_back(X);
            n += 1;
        }
        else if (q == 'B') {
            string Y; cin >> Y;
            dq2.push_front(Y);
            n += 1;
        }
        else if (q == 'C') {
            dq1.pop_front();
            n -= 1;
        }
        else if (q == 'D') {
            cout << dq1.front() << endl;
        }

        if ((int)dq1.size() < (n + 1) / 2) {
            dq1.push_back(dq2.front());
            dq2.pop_front();
        }
        else if ((int)dq1.size() > (n + 1) / 2) {
            dq2.push_front(dq1.back());
            dq1.pop_back();
        }
    }
}

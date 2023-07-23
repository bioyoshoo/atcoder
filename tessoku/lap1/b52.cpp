#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, X; cin >> N >> X; X--;
    string A; cin >> A;
    queue<int> que;

    que.push(X);
    A[X] = '@';

    while (!que.empty()) {
        int pos = que.front();
        if (pos > 0 && A[pos - 1] == '.') {
            A[pos - 1] = '@';
            que.push(pos - 1);
        }
        if (pos + 1 < N && A[pos + 1] == '.') {
            A[pos + 1] = '@';
            que.push(pos + 1);
        }

        que.pop();
    }

    cout << A << endl;
}

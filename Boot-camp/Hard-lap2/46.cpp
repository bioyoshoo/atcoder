#include <bits/stdc++.h>
using namespace std;

int main() {
    string X;
    cin >> X;
    int N = X.size();
    stack<char> sk;

    for (int i = 0; i < N; i++) {
        if (sk.size() != 0) {
            if (sk.top() == 'S' && X[i] == 'T') sk.pop();
            else sk.push(X[i]);
        }
        else sk.push(X[i]);
    }

    int ans = sk.size();
    cout << ans << endl;
}
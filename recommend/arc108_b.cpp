#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    stack<char> sk;
    for (auto s: S) {
        if (sk.empty()) sk.push(s);
        else {
            char last = sk.top();
            if (last == 'f' && s == 'o') {
                sk.pop();
                sk.push('0');
            }
            else if (last == '0' && s == 'x') sk.pop();
            else sk.push(s);
        }
    }
    int ans = 0;
    while (!sk.empty()) {
        char c; c = sk.top();
        if (c == '0') ans += 2;
        else ans += 1;
        sk.pop();
    }
    cout << ans << endl;
}
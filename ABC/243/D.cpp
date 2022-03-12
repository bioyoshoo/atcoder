#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, X;
    cin >> N >> X;
    string S;
    cin >> S;

    stack<char> T;
    for (char s: S) {
        if (s == 'U' && !T.empty() && (T.top() == 'R' || T.top() == 'L')) T.pop();
        else T.push(s);
    }

    string S_new = "";
    while (!T.empty()) {
        S_new += T.top();
        T.pop();
    }
    if (S_new.size() > 0) reverse(S_new.begin(), S_new.end());

    int64_t pos = X;
    for (int i = 0; i < N; i++) {
        if (S.at(i) == 'U') pos = pos / 2;
        else if (S.at(i) == 'L') pos = 2 * pos + 1;
        else if (S.at(i) == 'R') pos = 2 * pos + 2;
    }

    cout << pos << endl;
}
#include <bits/stdc++.h>
using namespace std;

int change_time(string S) {
    stack<pair<char, int>> sk;
    for (char s: S) {
        int n;
        if (sk.empty()) n = 1;
        else if (sk.top().first == s) {
            n = sk.top().second + 1;
            sk.pop();
        }
        else if (sk.top().first != s) n = 1;
        pair p = make_pair(s, n);
        sk.push(p);
    }

    int ans = 0;
    while (!sk.empty()) {
        ans += sk.top().second / 2;
        sk.pop();
    }

    return ans;
}

int main() {
    string S;
    cin >> S;
    int64_t K;
    cin >> K;

    int64_t one_seq = change_time(S);
    int64_t joint = change_time(S + S) - 2 * one_seq;
    cout << one_seq * K + joint * (K - 1) << endl;
}
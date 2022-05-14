#include <bits/stdc++.h>
using namespace std;

int main() {
    string S, T;
    cin >> S >> T;
    int N = S.size();
    set<char> change;
    for (char c: "atcoder") change.insert(c);

    bool ans = true;
    for (int i = 0; i < N; i++) {
        if (S[i] != T[i]) {
            if (S[i] == '@') {
                if (!change.count(T[i])) ans = false;
            }
            else if (T[i] == '@') {
                if (!change.count(S[i])) ans = false;
            }
            else ans = false;
        }
    }
    if (ans) cout << "You can win" << endl;
    else cout << "You will lose" << endl;
}
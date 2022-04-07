#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int N = S.size();

    bool ans = false;
    for (int i = 0; i <= N; i++) {
        for (int j = i; j <= N; j++) {
            string s_1 = S.substr(0, i);
            string s_2 = S.substr(j);
            string s_concat = s_1 + s_2;

            if (s_concat == "keyence") {
                ans = true;
                goto OUT;
            }
        }
    }
OUT:
    if (ans) cout << "YES" << endl;
    else cout << "NO" << endl;
}
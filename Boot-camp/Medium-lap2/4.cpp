#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int N = (int)S.size();

    int ans = 0;
    for (int s = N - 1; s >= 2; s--) {
        if (s % 2 == 1) continue;
        string s_1 = S.substr(0, s / 2);
        string s_2 = S.substr(s / 2, s / 2);

        if (s_1 == s_2) {
            ans = s;
            break;
        }
    }

    cout << ans << endl;
}
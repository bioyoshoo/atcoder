#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int K;
    cin >> K;
    int N = (int)S.size();

    set<string> seen;
    for (int i = 0; i < 26; i++) {
        int order = 0;
        for (int j = 0; j < N; j++) {
            if (S.at(j) == (char)('a' + i)) {
                for (int k = 0; j + k < N; k++) {
                    order++;
                    string s = S.substr(j, k + 1);
                    seen.insert(s);
                }
            }
        }
        if (order > 5) break;
    }

    string ans;
    int cnt = 1;
    for (string s: seen) {
        if (cnt == K) {
            ans = s;
            break;
        }
        cnt++;
    }

    cout << ans << endl;
}
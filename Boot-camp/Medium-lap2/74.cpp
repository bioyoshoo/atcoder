#include <bits/stdc++.h>
using namespace std;
const int64_t MAX = 100;

void chmin(int &a, int b) {
    if (a > b) a = b;
    return;
}

int main() {
    int n;
    cin >> n;
    vector<int> V(26, MAX);

    for (int i = 0; i < n; i++) {
        string S;
        cin >> S;

        vector<int> V_s(26);
        for (char c: S) V_s[c - 'a']++;

        for (int i = 0; i < 26; i++) chmin(V.at(i), V_s.at(i));
    }

    string ans = "";
    for (int i = 0; i < 26; i++) {
        int rep = V.at(i);
        for (int j = 0; j < rep; j++) ans += (char)('a' + i);
    }

    cout << ans << endl;
}
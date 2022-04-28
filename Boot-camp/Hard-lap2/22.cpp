#include <bits/stdc++.h>
using namespace std;

int main() {
    string S, T;
    cin >> S >> T;
    int n = S.size();
    vector<vector<int>> table(26, vector<int>(26, 0));

    for (int i = 0; i < n; i++) table[S[i] - 'a'][T[i] - 'a']++;

    bool flag = true;
    // row
    for (int i = 0; i < 26; i++) {
        int cnt = 0;
        for (int j = 0; j < 26; j++) {
            if (table[i][j] > 0) cnt++;
        }
        if (cnt > 1) flag = false;
    }
    // col
    for (int j = 0; j < 26; j++) {
        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            if (table[i][j] > 0) cnt++;
        }
        if (cnt > 1) flag = false;
    }

    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    string S, T;
    cin >> S >> T;
    int size = S.size();

    vector<vector<int>> table(26, vector<int>(26, 0));

    for (int i = 0; i < size; i++) {
        int from = S.at(i) - 'a', to = T.at(i) - 'a';
        if (from != to) table.at(from).at(to) = 1;
    }

    bool ans = true;
    // row
    for (int i = 0; i < 26; i++) {
        int flag_row = 0;
        for (int j = 0; j < 26; j++) flag_row += table.at(i).at(j);
        if (flag_row > 1) {
            ans = false;
            goto OUT;
        }
    }
    // col
    for (int j = 0; j < 26; j++) {
        int flag_col = 0;
        for (int i = 0; i < 26; i++) flag_col += table.at(i).at(j);
        if (flag_col > 1) {
            ans = false;
            goto OUT;
        } 
    }


OUT:
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}
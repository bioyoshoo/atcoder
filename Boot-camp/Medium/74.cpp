#include <bits/stdc++.h>
using namespace std;

void chmin(int &a, int b) {
    if (a > b) a = b;
    return;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> table(n, vector<int>(27, 0));
    for (int i = 0; i < n; i++) {
        string S;
        cin >> S;
        for (char s: S) table.at(i).at((int)(s - 'a'))++;
    }


    string ans = "";
    for (int j = 0; j < 27; j++) {
        int m = 100;
        for (int i = 0; i < n; i++) chmin(m, table.at(i).at(j));
        ans += string(m, (char)(j + 'a'));
    }

    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    cin >> N;
    vector<vector<int64_t>> table(10, vector<int64_t>(10, 0));

    for (int64_t n = 1; n <= N; n++) {
        string n_s = to_string(n);
        int size = n_s.size();
        int head = n_s[0] - '0', tail = n_s[size - 1] - '0';
        table[head][tail]++;
    }

    int64_t ans = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == j) ans += table[i][j] * table[i][j];
            else ans += table[i][j] * table[j][i];
        }
    }
    cout << ans << endl;
}
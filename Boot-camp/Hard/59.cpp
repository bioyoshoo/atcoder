#include <bits/stdc++.h>
using namespace std;

int64_t keta(int64_t n) {
    string n_s = to_string(n);
    return n_s.size();
}

int main() {
    int64_t N;
    cin >> N;

    vector<vector<int64_t>> table(9, vector<int64_t>(9, 0));
    for (int64_t n = 1; n <= N; n++) {
        if (n % 10 == 0) continue;
        
        int64_t head = n / pow(10, keta(n) - 1), tail = n % 10;
        head--;
        tail--;
        table[head][tail]++;
    }

    int64_t ans = 0;
    for (int i = 0 ; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            ans += table[i][j] * table[j][i];
        }
    }
    
    cout << ans << endl;
}
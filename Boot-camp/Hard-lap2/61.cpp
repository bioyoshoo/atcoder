#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int n = S.size();
    int64_t K;
    cin >> K;

    vector<int> s_vec(n);
    for (int i = 0; i < n; i++) s_vec[i] = (int)(S[i] - 'a');

    vector<int> to_a(n);
    for (int i = 0; i < n; i++) to_a[i] = (26 - s_vec[i]) % 26;
    
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            K %= 26;
            s_vec[n - 1] = (s_vec[n - 1] + K) % 26;
        }
        else if (K >= to_a[i]) {
            s_vec[i] = (s_vec[i] + to_a[i]) % 26;
            K -= to_a[i];
        }
    }

    for (int i = 0; i < n; i++) cout << (char)(s_vec[i] + 'a');
    cout << endl;
}
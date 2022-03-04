#include <bits/stdc++.h>
using namespace std;
const int64_t mod = 1e9 + 7;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    vector<int64_t> M(30, 0);
    for (char s: S) M[s - 'a']++;

    int64_t ans = 1;
    for (int i = 0; i < 26; i++) {
        ans *= M.at(i) + 1;
        ans %= mod;
    }

    cout << (ans - 1) % mod << endl;
}
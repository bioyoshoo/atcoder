#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);

    int64_t one_block = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (A.at(i) > A.at(j)) {
                one_block++;
                one_block %= mod;
            }
        }
    }

    int64_t joint = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (A.at(i) > A.at(j)) {
                joint++;
                joint %= mod;
            }
        }
    }

    int64_t comb = K * (K - 1) / 2;
    comb %= mod;
    
    int64_t ans = one_block * K + joint * comb;
    ans %= mod;

    cout << ans << endl;
}

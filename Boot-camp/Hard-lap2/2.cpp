#include <bits/stdc++.h>
using namespace std;
const int64_t mod = 1e9 + 7;

int main() {
    int64_t N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);
    int64_t one_block = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (A[i] > A[j]) one_block++;
        }
    }

    vector<int> A2;
    for (int r = 0; r < 2; r++) for (int i = 0; i < N; i++) A2.push_back(A[i]);
    int64_t two_block = 0;
    for (int i = 0; i < 2 * N; i++) {
        for (int j = i + 1; j < 2 * N; j++) {
            if (A2[i] > A2[j]) two_block++;
        }
    }

    int64_t joint = two_block - 2 * one_block;
    int64_t ans = (K * (one_block % mod) + (K * (K - 1) / 2 % mod) * (joint % mod)) % mod;
    cout << ans << endl;
}
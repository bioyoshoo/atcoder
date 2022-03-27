#include <bits/stdc++.h>
using namespace std;
const int64_t mod = 1000000007;

int main() {
    int N;
    cin >> N;

    vector<string> S(2);
    for (int i = 0; i < 2; i++) cin >> S.at(i);

    vector<int> Block;
    for (int i = 0; i < N;) {
        int j = i + 1;
        while (j < N && S[0][i] == S[0][j]) j++;
        Block.push_back(j - i);
        i = j;
    }

    int block_n = (int)Block.size();
    vector<int64_t> dp(block_n);
    if (Block[0] == 1) dp[0] = 3;
    else if (Block[0] == 2) dp[0] = 6;
    
    for (int i = 1; i < block_n; i++) {
        if (Block[i - 1] == 1 && Block[i] == 1) dp[i] = (dp[i - 1] * 2) % mod;
        else if (Block[i - 1] == 1 && Block[i] == 2) dp[i] = (dp[i - 1] * 2) % mod;
        else if (Block[i - 1] == 2 && Block[i] == 1) dp[i] = dp[i - 1] % mod;
        else if (Block[i - 1] == 2 && Block[i] == 2) dp[i] = (dp[i - 1] * 3) % mod;
    }

    cout << dp[block_n - 1] << endl;
}
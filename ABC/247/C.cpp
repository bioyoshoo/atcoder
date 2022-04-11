#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> dp(N + 1);
    dp.at(1).push_back(1);
    for (int i = 2; i <= N; i++) {
        vector<int> insert;
        insert = dp.at(i - 1);
        insert.push_back(i);
        for (int j: dp.at(i - 1)) insert.push_back(j);
        dp.at(i) = insert;
    }

    for (int n: dp[N]) cout << n << " ";
    cout << endl;
}
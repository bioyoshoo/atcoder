#include <bits/stdc++.h>
using namespace std;

template<class T> bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    else return false;
}

int main() {
    int N;
    cin >> N;
    vector<long double> A(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);
    
    vector<vector<long double>> dp(N + 1, vector<long double>(2, 0));
    vector<vector<int>> pre(N + 1, vector<int>(2, -1));
    dp[0][0] = 1.0;
    for (int i = 0; i < N; i++) {
        if (chmax(dp[i + 1][0], dp[i][0])) pre[i + 1][0] = 0;
        if (chmax(dp[i + 1][0], dp[i][1] / A[i])) pre[i + 1][0] = 1;

        if (chmax(dp[i + 1][1], dp[i][1])) pre[i + 1][1] = 1;
        if (chmax(dp[i + 1][1], dp[i][0] * A[i])) pre[i + 1][1] = 0;
    }

    vector<int> ans;
    int material = 0, day = N;
    while (pre[day][material] != -1) {
        int next_material = pre[day][material];
        if (material != next_material) ans.push_back(1);
        else ans.push_back(0);
        material = next_material;
        day--;
    }
    reverse(ans.begin(), ans.end());
    for (auto a: ans) cout << a << " ";
    cout << endl;
}
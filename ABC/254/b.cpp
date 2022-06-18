#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<vector<int>> ans(N);

    ans[0].push_back(1);
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i + 1; j++) {
            if (j == 0 || j == i + 1) ans[i].push_back(1);
            else {
                int a = ans[i - 1][j - 1] + ans[i - 1][j];
                ans[i].push_back(a);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i + 1; j++) cout << ans[i][j] << " ";
        cout << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> B(N);
    for (int i = 0; i < N; i++) cin >> B.at(i);

    bool ans = true;
    vector<int> res;
    for (int i = 0; i < N; i++) {
        int n = B.size();
        int skip_idx = -1;
        for (int j = 0; j < n; j++) {
            if (B[j] > j + 1) {
                ans = false;
                break;
            }
            if (B[j] == j + 1) skip_idx = j;
        }
        if (skip_idx == -1) ans = false;
        if (!ans) break;
        
        vector<int> new_B;
        for (int j = 0; j < n; j++) {
            if (skip_idx == j) {
                res.push_back(B[j]);
                continue;
            }
            else new_B.push_back(B[j]);
        }
        B = new_B;
    }
    if (ans) {
        reverse(res.begin(), res.end());
        for (auto r: res) cout << r << endl;
    }
    else cout << -1 << endl;
}
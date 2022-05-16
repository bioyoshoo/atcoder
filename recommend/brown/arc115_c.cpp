#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    
    vector<int> ans(N + 1, 1);
    for (int n = 1; n <= N; n++) {
        for (int m = 2 * n; m <= N; m += n) {
            if (ans[n] != ans[m]) continue;
            else ans[m]++;
        }
    }
    
    for (int i = 1; i <= N; i++) cout << ans[i] << " ";
    cout << endl;
}
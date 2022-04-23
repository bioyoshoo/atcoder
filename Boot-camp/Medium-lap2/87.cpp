#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    cin >> N;
    vector<int64_t> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);
    for (int i = 0; i < N; i++) cin >> B.at(i);

    int64_t ans = 0;
    int64_t shortage = 0;
    vector<int64_t> stock(N, 0);
    for (int i = 0; i < N; i++) {
        if (A[i] < B[i]) {
            ans++;
            shortage += B[i] - A[i];
        }
        else if (A[i] > B[i]) {
            stock.at(i) = A[i] - B[i];
        }
    }
    sort(stock.rbegin(), stock.rend());

    if (shortage == 0) cout << ans << endl;
    else {
        for (int i = 0; i < N; i++) {
            if (stock[i] == 0) continue;

            shortage -= stock[i];
            ans++;

            if (shortage <= 0) break;
        }
        if (shortage > 0) cout << -1 << endl;
        else cout << ans << endl;
    }
}
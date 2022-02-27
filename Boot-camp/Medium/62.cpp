#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int64_t> A(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);

    int64_t ans, min_ind = 0;
    while (min_ind < N - 1) {
        sort(A.begin(), A.end());

        for (int i = 0; i < N; i++) {
            if (A.at(i) != 0) {
                min_ind = i;
                break;
            }
        }
        ans = A.at(min_ind);
        for (int i = min_ind + 1; i < N; i++) A.at(i) = A.at(i) % ans;
    }
    cout << ans << endl;
}
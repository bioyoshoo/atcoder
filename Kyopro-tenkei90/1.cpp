#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, L, K;
    cin >> N >> L >> K;

    vector<int64_t> A(N);
    for (int64_t i = 0; i < N; i++) cin >> A.at(i);

    const int64_t MAX = pow(10, 10);
    int64_t left = 0, right = MAX;

    while (right - left > 1) {
        int64_t mid = left + (right - left) / 2;

        int64_t borders = K, pre_length = 0;
        bool flag = false;
        for (int64_t i = 0; i < N; i++) {
            if (A.at(i) - pre_length >= mid) {
                borders--;
                pre_length = A.at(i);
            }

            if (borders == 0 && L - pre_length >= mid) {
                flag = true;
                break;
            }
        }

        if (flag) left = mid;
        else right = mid;
    }

    cout << left << endl;
}
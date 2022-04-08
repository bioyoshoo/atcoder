#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, T;
    cin >> N >> T;
    vector<int64_t> Time(N);
    for (int i = 0; i < N; i++) cin >> Time.at(i);

    int64_t ans = 0;
    int64_t pre_start = Time.at(0);
    int64_t pre_end = pre_start + T;
    for (int i = 1; i < N; i++) {
        int64_t start = Time.at(i);

        if (start <= pre_end) pre_end = start + T;
        else {
            ans += pre_end - pre_start;
            pre_start = start;
            pre_end = pre_start + T;
        }
    }
    ans += pre_end - pre_start;

    cout << ans << endl;
}
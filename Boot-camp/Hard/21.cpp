#include <bits/stdc++.h>
using namespace std;
const int64_t INF = 1e10;

int main() {
    int N;
    cin >> N;
    vector<int64_t> A(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);

    sort(A.begin(), A.end());

    int64_t ans_1, ans_2;
    long double min_d = INF;
    ans_1 = *(prev(A.end()));
    
    for (int i = 0; i < N; i++) {
        long double d_from_center = abs(A.at(i) - (long double)ans_1 / 2);
        if (d_from_center < min_d) {
            ans_2 = A.at(i);
            min_d = d_from_center;
        }
    }

    cout << ans_1 << " " << ans_2 << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    cin >> N;
    vector<int64_t> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);
    for (int i = 0; i < N; i++) cin >> B.at(i);
    
    int64_t sub_cnt = 0, permit_cnt = 0;
    for (int i = 0; i < N; i++) {
        sub_cnt += max((int64_t)0, A[i] - B[i]);
        permit_cnt += max((int64_t)0, (B[i] - A[i]) / 2);
    }

    if (sub_cnt <= permit_cnt) cout << "Yes" << endl;
    else cout << "No" << endl;
}
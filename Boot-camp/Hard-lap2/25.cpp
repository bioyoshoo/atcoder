#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    cin >> N;
    vector<int64_t> C(N - 1), S(N - 1), F(N - 1);
    for (int i = 0; i < N - 1; i++) cin >> C.at(i) >> S.at(i) >> F.at(i);

    vector<int64_t> ans(N);
    for (int start = 0; start < N; start++) {
        int64_t arrive_time = 0;
        for (int i = start; i < N - 1; i++) {
            int64_t leave_time;
            if (arrive_time <= S[i]) leave_time = S[i];
            else {
                if ((arrive_time - S[i]) % F[i] == 0) leave_time = arrive_time;
                else leave_time = arrive_time + F[i] - (arrive_time - S[i]) % F[i];
            }
            arrive_time = leave_time + C[i];
        }
        ans.at(start) = arrive_time;
    }
    for (int i = 0; i < N; i++) cout << ans[i] << endl;
}
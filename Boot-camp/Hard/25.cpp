#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int64_t> C(N - 1), S(N - 1), F(N - 1);
    for (int i = 0; i < N - 1; i++) {
        cin >> C.at(i) >> S.at(i) >> F.at(i);
    }

    vector<int64_t> ans(N, 0);

    for (int start = 0; start < N; start++) {
        vector<int64_t> dp(N, 0);
        for (int i = start; i < N - 1; i++) {
            
            int64_t lag = dp.at(i) - S.at(i);
            int64_t start_time;
            
            if (lag <= 0) start_time = S.at(i);
            else start_time = S.at(i) + ((lag + F.at(i) - 1) / F.at(i)) * F.at(i);

            dp.at(i + 1) = start_time + C.at(i);
        }

        ans.at(start) = dp.at(N - 1);
    }

    for (int a: ans) cout << a << endl;
}

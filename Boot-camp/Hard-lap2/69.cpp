#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    cin >> N;
    vector<int64_t> A(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);
    sort(A.begin(), A.end());

    vector<int64_t> res;
    int forward = 0, back = N - 1;
    for (int i = 0; i < N - 1; i++) {
        int64_t add;
        if (i % 2 == 0) add = A.at(back), back--;
        else add = A.at(forward), forward++;
        res.push_back(add);
    }

    int64_t ans = max(abs(res.at(0) - A.at(forward)), abs(res.at(N - 2) - A.at(forward)));
    for (int i = 1; i < N - 1; i++) {
        ans += abs(res.at(i) - res.at(i - 1));
    }
    cout << ans << endl;
}
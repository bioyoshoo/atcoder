#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) cin >> H.at(i);

    vector<int> dp(N);
    dp.at(0) = H.at(0);

    for (int i = 1; i < N; i++) {
        int diff = H.at(i) - H.at(i - 1);
        if (diff > 0) dp.at(i) = dp.at(i - 1) + diff;
        else dp.at(i) = dp.at(i - 1);
    }

    cout << dp.at(N - 1) << endl;
}
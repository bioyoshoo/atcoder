#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> V(N);
    for (int i = 0; i < N; i++) cin >> V.at(i);

    sort(V.begin(), V.end());

    int64_t ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            int a = V.at(i), b = V.at(j);
            auto iter1 = upper_bound(V.begin(), V.end(), b);
            auto iter2 = lower_bound(V.begin(), V.end(), a + b);
            int64_t dist = distance(iter1, iter2);
            ans += dist;
        }
    }

    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    cin >> N;
    vector<int64_t> V(5);
    for (int i = 0; i < 5; i++) cin >> V.at(i);

    sort(V.begin(), V.end());

    int64_t ans = (N + V[0] - 1) / V[0] + 4;
    cout << ans << endl;
}
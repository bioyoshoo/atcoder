#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, A, B, C, D, E;
    cin >> N >> A >> B >> C >> D >> E;

    vector<int64_t> Num = { A, B, C, D, E };
    sort(Num.begin(), Num.end());
    int64_t m = Num.at(0);

    int64_t g = (N + m - 1) / m;
    int64_t ans = 5 + g - 1;

    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, A, B;
    cin >> N >> A >> B;
    vector<int64_t> cord(N);
    for (int i = 0; i < N; i++) cin >> cord.at(i);

    int64_t ans = 0;
    for (int i = 1; i < N; i++) {
        if (A * (cord.at(i) - cord.at(i - 1)) <= B) ans += A * (cord.at(i) - cord.at(i - 1));
        else ans += B;
    }

    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int64_t> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);
    for (int i = 0; i < N; i++) cin >> B.at(i);

    int64_t plus = 0, minus = 0;
    for (int i = 0; i < N; i++) {
        int64_t diff = B.at(i) - A.at(i);
        if (diff > 0) plus += diff;
        else if (diff < 0) minus += abs(diff);
    }

    if (plus >= 2 * minus) cout << "Yes" << endl;
    else cout << "No" << endl;
}
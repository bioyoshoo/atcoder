#include <bits/stdc++.h>
using namespace std;
const int64_t MAX = 1e9 + 1;

int64_t d(int64_t n) {
    string n_s = to_string(n);
    return (int64_t)n_s.size();
}

int main() {
    int64_t A, B, X;
    cin >> A >> B >> X;

    int64_t top = MAX, bottom = 0;
    while (top - bottom > 1) {
        int64_t n = bottom + (top - bottom) / 2;
        if (A * n + B * d(n) > X) top = n;
        else bottom = n;
    }

    cout << bottom << endl;
}
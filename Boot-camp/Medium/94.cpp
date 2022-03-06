#include <bits/stdc++.h>
using namespace std;
const int64_t MAX = 1e9 + 1;

int64_t digit_num(int64_t n) {
    string n_s = to_string(n);
    return n_s.size();
}

int main() {
    int64_t A, B, X;
    cin >> A >> B >> X;

    int64_t top = MAX, bottom = 0, mid, cost;
    while (top - bottom > 1) {
        mid = bottom + (top - bottom) / 2;
        cost = A * mid + B * digit_num(mid);
        if (cost <= X) bottom = mid;
        else top = mid;
    }

    cout << bottom << endl;
}
#include <bits/stdc++.h>
using namespace std;

int64_t recursive(int64_t L, int64_t X) {
    if (L == 0) return 1;
    
    int64_t prev_size = pow(2, L + 1) - 3;
    if (X <= 1) return 0;
    else if (1 < X && X <= prev_size + 1) return recursive(L - 1, X - 1);
    else if (X == prev_size + 2) return recursive(L - 1, prev_size) + 1;
    else if (prev_size + 2 < X && X <= 2 * prev_size + 2) return recursive(L - 1, prev_size) + 1 + recursive(L - 1, X - prev_size - 2);
    else return 2 * recursive(L - 1, prev_size) + 1;
}

int main() {
    int64_t N, X;
    cin >> N >> X;

    cout << recursive(N, X) << endl;
}
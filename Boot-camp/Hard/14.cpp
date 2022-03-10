#include <bits/stdc++.h>
using namespace std;

int64_t cnt_digits(int64_t n) {
    string n_s = to_string(n);
    int64_t ans = n_s.size();
    return ans;
}

int main() {
    int64_t N;
    cin >> N;
    
    int64_t A_max = 1;
    for (int64_t A = 2; A * A <= N; A++) {
        if (N % A == 0) A_max = A;
    }

    cout << cnt_digits(N / A_max) << endl;
}
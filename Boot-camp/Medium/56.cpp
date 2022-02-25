#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;

int main() {
    int64_t N, K, S;
    cin >> N >> K >> S;
    
    vector<int64_t> A(N);
    for (int i = 0; i < N; i++) {
        if (i < K) A.at(i) = S;
        else if (S == 1) A.at(i) = 2;
        else A.at(i) = S - 1;
    }

    for (int64_t a: A) cout << a << endl;
}
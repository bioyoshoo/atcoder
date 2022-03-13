#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;

bool is_prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    set<int> prime_set;
    for (int i = 2; i <= MAX; i++) {
        if (is_prime(i)) prime_set.insert(i);
    }
    
    vector<int> V(MAX + 1, 0);
    for (int n: prime_set) {
        int m = 2 * n - 1;
        if (prime_set.count(m)) V.at(m) = 1;
    }

    for (int i = 1; i <= MAX; i++) V.at(i) += V.at(i - 1);
    
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        cout << V.at(l) - V.at(r - 1) << endl;
    }
}